module.exports = {
  timeAllowed: 2, points: 4, category: 'AI', isCodingChallenge: true, tests: [
    {
      name: 'Easy',
      inputs: ['4',
               '5',
               '0',
               '3',
               '0 1 2',
               '1 0 1',
               '1 2 4',
               '1 3 5',
               '2 3 3'],
      outputs: ['0','1','3']
    },
    {
      name: 'Still easy',
      inputs: ['5',
               '5',
               '0',
               '4',
               '0 1 2',
               '1 2 2',
               '1 3 7',
               '2 3 2',
               '3 4 4'
              ],
      outputs: ['0','1', '2', '3', '4']
    },
    {
      name: 'Which one is smaller?',
      inputs: ['5',
               '5',
               '0',
               '4',
               '0 1 2',
               '1 2 2',
               '1 3 4',
               '2 3 2',
               '3 4 4'
              ],
      outputs: ['0','1', '3', '4']
    }
  ]
  ,python:
  `
nb_nodes = int(raw_input())
nb_arcs = int(raw_input())
initial_node = int(raw_input())
final_node = int(raw_input())
arcs = []
for i in xrange(nb_arcs):
   arcs.append(raw_input().replace("\n", "").replace("\r", ""))
`, javascript:
  `
"use strict";

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

var nbNodes = parseInt(readline())
var nbArcs = parseInt(readline())
var initialNode = parseInt(readline())
var finalNode = parseInt(readline())
var arcs = []
for(var i=0; i < nbArcs; i++) {
  arcs.push(readline());
}
`};
