"use strict";
var spawnSync = require('child_process').spawnSync;
var os = require('os');

class Tester {
	constructor(path, bin) {
		this.bin = bin;
		this.path = path;
		this.test = [];
	}

	setTest(test) {
		this.test = test;
	}

	verifyOutput(output, expected) {
		if (output.length != expected.length) {
			return false;
		}
		for (let i in output) {
			if (output[i] !== expected[i]) {
				return false;
			}
		}

		return true;
	}
	
	run() {
		let result = {results: []}
		let successCount = 0;
		this.test.tests.forEach(test => {
			let options = {
				timeout: this.test.timeAllowed*1000,
				input: test.inputs.join(os.EOL),
				encoding: 'utf-8'
			}
			let res = spawnSync(this.bin, [this.path], options);
			console.log('-----------------------------------');
			console.log(`stdout: ${res.stdout.trim()}`);
			console.log(`stderr: ${res.stderr.trim()}`);
			console.log('-----------------------------------');
			let isSuccess = this.verifyOutput(res.stdout.trim().replace(/\r/g,'').split('\n'), test.outputs)
			let isTimeout = (res.error !== undefined && res.error.code === 'ETIMEDOUT');
			result.results.push({name: test.name, isSuccess: isSuccess, isTimeout: isTimeout});
			if (isSuccess) successCount++;
		});

		result.percent = successCount/this.test.tests.length;
		return result;
	}
}

module.exports = Tester;
