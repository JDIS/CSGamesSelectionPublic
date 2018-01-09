"use strict";
var Tester = require('./tester');
var fs = require('fs');

var args = process.argv.slice(2);
if (args.length != 2) {
	console.log('--- INVALID USE OF VALIDATOR ---');
	console.log('(usage): node validator.js <script file> <validation file>');
	return;
}

var command = args[0].split(' ');
var jsonstring = fs.readFileSync(`./${args[1]}`);
var validator = JSON.parse(jsonstring);


var program = command[0]
var arg = command.length > 1? command[1] : ""
var tester = new Tester(arg, program);
tester.setTest(validator);
var res = tester.run();
for(var result of res.results) {
	var timeout = result.isTimeout ? 'timeout' : '';
	var success = result.isSuccess ? 'Success' : 'Failed';
	console.log(`Test ${result.name} --- ${success} ${timeout}`);
}
console.log(`Pourcentage de réussite: ${res.percent*100}%`);
