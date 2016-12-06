/**
 * @Description: This file describes the different SQL queries.
 * Export additional functions in module.exports at the bottom of the file
 */

/**
 * Inserts into Experiment Table
 * Accepts the following api string format
 *  api/create_experiment?envSide=(int)&envSize=(int)&duration=(int)&startFood=(int)&maxFood=(int)
 * Returns
 *  Exp_ID
 */
function create_experiment(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.query.envSide, req.query.envSize, req.query.duration, req.query.startFood, req.query.maxFood];
    client
        .query('INSERT INTO "ACSchema"."Experiment"("Env_Side", "Env_Size", "SIM_Duration", "Start_Ant_Food", "Max_Ant_Food")VALUES ($1, $2, $3, $4, $5) RETURNING "Exp_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                } else {
                    console.log(result.rows);
                    res.json(result.rows[0].Exp_ID);
                }
            });
}
/**
 * Inserts into Generation Table
 * Accepts the following api string format
 *  api/create_generation?expID=(int)&parents=(int)&envs=(int)&genCM=(int)
 * Returns
 *  Gen_ID
 */
function create_generation(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.query.expID, req.query.parents, req.query.envs, req.query.genCM];
    console.log(req.query);
    client
        .query('INSERT INTO "ACSchema"."Generation"( "Exp_ID", "Parents", "Environments", "Gen_CM") VALUES ($1, $2, $3, $4) RETURNING "Gen_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query' + err.detail);
                    return console.error('error running query', err);
                } else {
                    console.log(result.rows);
                    res.json(result.rows[0].Gen_ID);
                }
            });
}
/**
 * Inserts into Entity Table
 * Accepts the following api string format
 *  api/create_entity?genBorn=(int)&genDied=(int)
 * Returns
 *  Ant_ID
 */
function create_entity(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.query.genBorn, req.query.genDied];
    client
        .query('INSERT INTO "ACSchema"."Entity"( "Gen_Born", "Gen_Died") VALUES ($1, $2) RETURNING "Ant_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                } else {
                    console.log(result.rows);
                    res.json(result.rows[0].Ant_ID);
                }
            });
}
/**
 * Inserts into Environment Table
 * Accepts the following api string format
 *  api/create_environment?envType=(int)&noise=(int)&frequency=(int)&interp=(int)&fType=(int)&fOctaves=(int)&fLanc=(int)&fGain=(int)&envGen=(int)
 * Returns
 *  Ant_ID
 */
function create_environment(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.query.envType, req.query.noise, req.query.frequency, req.query.interp, req.query.fType, req.query.fOctaves, req.query.fLanc, req.query.fGain, req.query.envGen];
    client
        .query('INSERT INTO "ACSchema"."Environment"( "Env_Type", "Noise", "Frequency", "Interp", "FractalType", "FractalOctaves", "FractalLancunarity", "FractalGain", "Env_Gen") VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING "Env_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                } else {
                    console.log(result.rows);
                    res.json(result.rows[0].Env_ID);
                }
            });
}
/**
 * TODO: CREATE SIMULATION TABLE IN DATABASE
 * TODO: GENERATION TABLE has INTEGER[] attributes (currently only takes a single integer req.antList)
 * Inserts into Simulation Table
 * Accepts the following api string format
 *  api/create_simulation?genID=(int)&envID=(int)&antList=(int)
 * Returns
 *  Ant_ID
 */
function create_simulation(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.query.genID, req.query.envID, req.query.antList];
    client
        .query('INSERT INTO "ACSchema"."Simulation"( "Gen_ID", "Env_ID", "Ant_List") VALUES ($1, $2, $3) RETURNING "Sim_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                } else {
                    console.log(result.rows);
                    res.json(result.rows[0].Sim_ID);
                }
            });
}
/**
 * TODO: CREATE SIMULATION TABLE IN DATABASE
 * TODO: GENERATION TABLE has INTEGER[] attributes (currently only takes a single integer req.antList)
 * Inserts into Simulation Table
 * Accepts the following api api/temp?gs=(string)&lifetime=(int)&fitness=(int)string format
 *
 * Returns
 *  Ant_ID
 */

 /**
  * Inserts into CreationMechanism Table
  * Accepts the following api string format
  *  api/create_mechanism?cmID=(int)&purpose=(string)
  * Returns
  *  CM_ID
  */
 function create_mechanism(err, client, done, req, res) {
     if(err) {
         return console.error('error fetching client from pool', err);
     }
     var reqArr = [req.query.cmID, req.query.purpose];
     client
         .query('INSERT INTO "ACSchema"."CreationMechanism"( "CM_ID", "Purpose") VALUES ($1, $2) RETURNING "CM_ID"',
             reqArr,
             function(err, result) {
                 done();
                 if(err) {
                     res.send('error running query');
                     return console.error('error running query', err);
                 } else {
                     console.log(result.rows);
                     res.json(result.rows[0].CM_ID);
                 }
             });
           }

function temp(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    //var reqArr = [req.query.gs, req.query.lifetime, req.query.fitness];
    var reqArr = [req.query.gs, req.query.lifetime, req.query.parents, req.query.fitness];
    client
        //.query('INSERT INTO "ACSchema"."Temp"( "GS", "Lifetime", "Parents", "Fitness") VALUES ($1, $2, $3, $4)',
        .query('INSERT INTO "ACSchema"."Temp"( "GS", "Lifetime", "Parents", "Fitness") VALUES ($1, $2, $3, $4)',
            reqArr,
            function(err) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                }
                res.send("success");
            });
}
/**
 * Inserts into Search Table
 * Accepts the following search/temp?lifetime=(int)&type=(string)&netFood=(int)&posFood=(int)&negFood=(int)&members=(json[])
 */
function search(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    //var reqArr = [req.query.gs, req.query.lifetime, req.query.fitness];
    var reqArr = [req.query.lifetime, req.query.type, req.query.netFood, req.query.posFood, req.query.negFood, req.query.members];
    client
        .query('INSERT INTO "ACSchema"."Search"("Lifetime", "Type", "Net_Food", "Pos_Food", "Neg_Food", "Members") VALUES ($1, $2, $3, $4, $5, $6)',
            reqArr,
            function(err) {
                done();
                if(err) {
                    res.send('error running query');
                    return console.error('error running query', err);
                }
                res.send("success");
            });
}


function clientError(err, client) {
   console.error('idle client error', err.message, err.stack);
}

module.exports = {
    create_experiment: create_experiment,
    create_generation: create_generation,
    create_entity: create_entity,
    create_environment: create_environment,
    create_simulation: create_simulation,
    create_mechanism: create_mechanism,
    clientError: clientError,
    temp: temp
};
