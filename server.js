const express = require('express')
const app = express()

app.get('/', function (req, res) {
console.log("🚀 ~ file: server.js:5 ~ req:", req)

  res.send('Hello World')
})

app.listen(4000)

