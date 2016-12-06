// This application uses express as its web server
// for more info, see: http://expressjs.com
var express = require('express');
// This application uses node-postgress
// for more info, see: https://github.com/brianc/node-postgres
var pg = require('pg');

// create a new express server
var app = express();
app.set('port', (process.env.PORT || 3001));
// internal exports
var db = require('./queries.js');
var config = require('./config.js');

//this initializes a connection pool
//it will keep idle connections open for a 30 seconds
//and set a limit of maximum 10 idle clients
var config = config.pg;
var pool = new pg.Pool(config);

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
 * Inserts into CreationMechanism Table
 * Accepts the following api string format
 *  api/create_mechanism?cmID=(int)&purpose=(string)
 * Returns
 *  CM_ID
 */
 app.get('/api/create_mechanism', function (req, res) {
   pool.connect(function(err, client, done){
     db.create_mechanism(err, client, done, req, res);
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
    db.create_entity(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * Inserts into Environment Table
 * Accepts the following api string format
 *  api/create_environment?envType=(int)&noise=(int)&frequency=(int)&interp=(int)&fType=(int)&fLanc=(int)&fOctaves=(int)&fGain=(int)&envGen=(int)
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
 * Inserts into Simulation Table
 * Accepts the following api string format
 *  api/create_entity?genID=(int)&envID=(int)&antList=(int)
 * Returns
 *  Ant_ID
 */
app.get('/api/create_simulation', function (req, res) {
  console.log("SIMULATION");
  pool.connect(function(err, client, done){
    db.create_simulation(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * Inserts into Temp Table
 * Accepts the following api string format
 *  api/temp?GS=(varchar)&Lifetime=(int)&Parents=(int)&Fitness=(double)
 * Returns
 *
 */
app.get('/api/temp', function (req, res) {
  console.log(req.query);
  pool.connect(function(err, client, done){
    db.temp(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
/**
 * Inserts into Search Table
 * Accepts the following search/temp?lifetime=(int)&type=(string)&netFood=(int)&posFood=(int)&negFood=(int)&members=(json[])
 */
app.get('/api/search', function (req, res) {
  console.log(req.query);
  pool.connect(function(err, client, done){
    db.temp(err, client, done, req, res);
  });
  pool.on('error', function (err, client) {
    console.error('idle client error', err.message, err.stack)
  });
});
//app.listen(appEnv.port, '0.0.0.0', function() {
//  console.log("server starting on " + appEnv.url);
//});
app.listen(app.get('port'), function() {
  console.log('Find the server at: http://localhost:' + app.get('port')); // eslint-disable-line no-console
});
// PUT
