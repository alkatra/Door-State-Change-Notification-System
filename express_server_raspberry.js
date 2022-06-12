const express = require('express')
const app = express()
const port = 3000
let status = "False";

const bodyParser = require('body-parser');


app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())

// Test
app.get('/', (req, res) => {
  res.send('Hello World!')
})

// Send status
app.get('/status', (req, res) => {
        res.status(200).send(status)
})

// Post status
app.post('/status', (req, res) => {
        let s = req.body.data
        console.log("Received: " + s)
        if(s == "False" || s == "True") {
                status = s
        }
        res.status(200).send("Done");
})

app.listen(port, () => {
  console.log(`Listening on port ${port}`)
})
