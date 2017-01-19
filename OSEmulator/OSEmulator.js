module.exports = {timeAllowed: 2, points: 8, category: 'OS', isCodingChallenge: true, tests: [
	{name: 'Exemple', inputs: ['9',
                             'MOV a 3',
                             'XOR a 1',
                             'SUB a 2',
                             'MOV b 2',
                             'MOV c 3',
                             'XOR b c',
                             'MOV d 1',
                             'ADD d 2',
                             'SUB c 1'], outputs: ['0','1','2','3']}, 
  {name: 'Jumping', inputs: ['7',
                            'MOV c 40',
                            'MOV a 10',
                            'ADD b 1',
                            'SUB c 2',
                            'CMP a b',
                            'JNE 2',
                            'XOR a a'], outputs: ['0','10','20','0']}],python: 
`N = int(raw_input())
for i in xrange(N):
  cmd = raw_input()
`, javascript:
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

var N = parseInt(readline());
for(var i=0; i < N; i++) {
  var cmd = readline();
}
`};