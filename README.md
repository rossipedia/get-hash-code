GetHashCode()
=============

A small hashing function for strings based on .NET's `String.GetHashCode`

Installation
------------

```
npm install get-hash-code
```

Usage
-----

The module is exported as a single function, which when called with a
string argument returns the integer hash code:

```javascript
var getHashCode = require('get-hash-code');
console.log(getHashCode("foo"));
```

Outputs:

```
1502598398
```
