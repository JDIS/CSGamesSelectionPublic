"use strict";
var Tester = require('./tester');

var args = process.argv.slice(2);
if (args.length != 2) {
	console.log('--- INVALID USE OF VALIDATOR ---');
	console.log('(usage): node validator.js <script file> <validation file>');
	return;
}

var script = args[0];
var validator = require(`./${args[1]}`);

var bin = script.split('.')[1] == 'js' ? 'node': 'python';
var tester = new Tester(script, bin);
tester.setTest(validator);
var res = tester.run();
for(var result of res.results) {
	var timeout = result.isTimeout ? 'timeout' : '';
	var success = result.isSuccess ? 'Success' : 'Failed';
	console.log(`Test ${result.name} --- ${success} ${timeout}`);
}
console.log(`Pourcentage de réussite: ${res.percent*100}%`);