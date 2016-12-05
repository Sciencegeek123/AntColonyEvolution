/*eslint-env node*/

//------------------------------------------------------------------------------
// node.js starter application for Bluemix
//------------------------------------------------------------------------------

// This application uses express as its web server
// for more info, see: http://expressjs.com
var express = require('express');
var pg = require('pg');

// cfenv provides access to your Cloud Foundry environment
// for more info, see: https://www.npmjs.com/package/cfenv
var cfenv = require('cfenv');

// create a new express server
var app = express();

//exports
var db = require('./queries.js');
var config = require('./config.js');

//this initializes a connection pool
//it will keep idle connections open for a 30 seconds
//and set a limit of maximum 10 idle clients
var config = config.pg;
var pool = new pg.Pool(config);

// serve the files out of ./public as our main files
app.use(express.static(__dirname + '/public'));

// get the app environment from Cloud Foundry
var appEnv = cfenv.getAppEnv();

/**********************************************************************************************************************
                                            GET operations
 *********************************************************************************************************************/

app.get('/api/Puppies/:id', function (req, res) {
  pool.connect(function(err, client, done){
    db.getPuppy(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});

app.get('/api/users', function(req, res) {
  var obj = {
    user_id: req.params.id,
    token: req.params.token,
    geo: req.params.geo
  };

  res.send(req.query);
  //res.json(req);
});

/**********************************************************************************************************************
                                          PUT operations
 *********************************************************************************************************************/
/**
 * Inserts into Experiment Table
 * Accepts the following api string format
 *  api/create_experiment?envSide=(int)&envSize=(int)&duration=(int)&startFood=(int)&maxFood=(int)
 * Returns
 *  Exp_ID
 */
app.get('/api/create_experiment', function (req, res) {
  pool.connect(function(err, client, done){
    db.create_experiment(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * TODO: GENERATION TABLE has INTEGER[] attributes
 * Inserts into Generation Table
 * Accepts the following api string format
 *  api/create_generation?expID=(int)&parents=(int)&envs=(int)&genCM=(int)
 * Returns
 *  Gen_ID
 */
app.get('/api/create_generation', function (req, res) {
  pool.connect(function(err, client, done){
    db.create_generation(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * Inserts into Entity Table
 * Accepts the following api string format
 *  api/create_entity?genBorn=(int)&genDied=(int)
 * Returns
 *  Ant_ID
 */
app.get('/api/create_entity', function (req, res) {
  pool.connect(function(err, client, done){
    db.create_experiment(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * Inserts into Environment Table
 * Accepts the following api string format
 *  api/create_environment?envType=(int)&noise=(int)&frequency=(int)&interp=(int)&fType=(int)&fOctaves=(int)&fOctaves=(int)&fGain=(int)&envGen=(int)
 * Returns
 *  Ant_ID
 */
app.get('/api/create_environment', function (req, res) {
  pool.connect(function(err, client, done){
    db.create_environment(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * TODO: CREATE SIMULATION TABLE IN DATABASE
 * TODO: GENERATION TABLE has INTEGER[] attributes
 * Inserts into Simulation Table
 * Accepts the following api string format
 *  api/create_entity?genID=(int)&envID=(int)&antList=(int)
 * Returns
 *  Ant_ID
 */
app.get('/api/create_simulation', function (req, res) {
  pool.connect(function(err, client, done){
    db.create_simulation(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
app.listen(appEnv.port, '0.0.0.0', function() {
  console.log("server starting on " + appEnv.url);
});

// PUT