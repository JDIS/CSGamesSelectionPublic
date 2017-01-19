var a = {
  operators: [
	{
		type: 'number',
		content: 3,
		position: 0
	},
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'string',
		content: '+',
		position: 1
	}
  ]
};

var b = {
  operators: [
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'number',
		content: 4,
		position: 0
	},
	{
		type: 'string',
		content: '-',
		position: 1
	}
  ]
};

var c = {
  operators: [
	{
		type: 'number',
		content: 4,
		position: 0
	},
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'string',
		content: '/',
		position: 1
	}
  ]
};

var d = {
  operators: [
	{
		type: 'number',
		content: 4,
		position: 0
	},
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'string',
		content: '*',
		position: 1
	}
  ]
};

var e = {
  operators: [
	{
		type: 'number',
		content: 4,
		position: 0
	},
	{
		type: 'number',
		content: 2,
		position: 2
	},
	{
		type: 'string',
		content: '^',
		position: 1
	}
  ]
};

var f = {
  operators: [
	{
		type: 'string',
		content: '(',
		position: 0
	},
	{
		type: 'number',
		content: 1,
		position: 1
	},
	{
		type: 'string',
		content: '+',
		position: 2
	},
	{
		type: 'number',
		content: 5,
		position: 3
	},
	{
		type: 'string',
		content: ')',
		position: 4
	},
	{
		type: 'string',
		content: '/',
		position: 5
	},
	{
		type: 'number',
		content: 3,
		position: 6
	}
  ]
};

var g = {
  operators: [
	{
		type: 'string',
		content: '(',
		position: 0
	},
	{
		type: 'number',
		content: 5,
		position: 3
	},
	{
		type: 'string',
		content: '*',
		position: 4
	},
	{
		type: 'number',
		content: 1,
		position: 1
	},
	{
		type: 'string',
		content: '^',
		position: 6
	},
	{
		type: 'string',
		content: '-',
		position: 8
	},
	{
		type: 'number',
		content: 2,
		position: 7
	},
	{
		type: 'string',
		content: '+',
		position: 2
	},
	{
		type: 'number',
		content: 5,
		position: 9
	},
	{
		type: 'string',
		content: '/',
		position: 11
	},
	{
		type: 'string',
		content: ')',
		position: 10
	},
	{
		type: 'number',
		content: 10,
		position: 5
	},
	{
		type: 'number',
		content: 4,
		position: 12
	}
  ]
};

module.exports = {timeAllowed: 2, points: 2, category: 'Software', isCodingChallenge: true, tests: [
	{name: 'Simple addition', inputs: [JSON.stringify(a)], outputs: ['5']},
	{name: 'Simple soustraction', inputs: [JSON.stringify(b)], outputs: ['2']},
	{name: 'Simple division', inputs: [JSON.stringify(c)], outputs: ['2']},
	{name: 'Simple multiplication', inputs: [JSON.stringify(d)], outputs: ['8']},
	{name: 'Simple puissance', inputs: [JSON.stringify(e)], outputs: ['16']},
	{name: 'Simple ordre des opérations', inputs: [JSON.stringify(f)], outputs: ['2']},
	{name: 'Opération complexe', inputs: [JSON.stringify(g)], outputs: ['124']}
]};