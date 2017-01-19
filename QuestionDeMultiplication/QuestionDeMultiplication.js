module.exports = {timeAllowed: 2, points: 4, category: 'Reverse', isCodingChallenge: true, tests: [
	{name: 'Easy', inputs: ['1'], outputs: ['2']},
	{name: 'Medium', inputs: ['1,2,3'], outputs: ['30']},
  {name: 'Saignant', inputs: ['2,4,10'], outputs: ['609']},
  {name: 'Interesting', inputs: ['2'], outputs: ['3']},
  {name: 'HowCanThisBe?', inputs: ['1,2'], outputs: ['6']}],python: `csv = raw_input()`, javascript:
`"use strict";

const fs = require("fs");

const BUFSIZ = 65536;
let buf = new Buffer(BUFSIZ);
buf.fill('\x00');
let response = [""];
try {
  fs.readSync(process.stdin.fd, buf, 0, BUFSIZ, null);
  const stopIdx = buf.indexOf(0);
  buf = buf.slice(0,stopIdx);
} catch(e) {
  console.warn(e);
  console.warn("No inputs in defi");
  process.exit(1);
}

response = buf.toString("utf-8");
let idx__ = 0;
let lines__ = response.split('\r\n');

var readline = () => {
    idx__++;
    return lines__[idx__-1];
};


var csv = readline();
`};