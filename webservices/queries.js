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
 * TODO: GENERATION TABLE has INTEGER[] attributes (currently only takes a single integer req.parents)
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
    client
        .query('INSERT INTO "ACSchema"."Generation"( "Exp_ID", "Parents", "Environments", "Gen_CM") VALUES ($1, $2, $3, $4) RETURNING "Gen_ID"',
            reqArr,
            function(err, result) {
                done();
                if(err) {
                    res.send('error running query');
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
        .query('INSERT INTO "ACSchema"."Entity"( "Gen_Born", "Gen_Died") VALUES ($1, $2,) RETURNING "Ant_ID"',
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
 * Accepts the following api/search?lifetime=(int)&type=(string)&netFood=(int)&posFood=(int)&negFood=(int)&members=(json[])
 */
function search(err, client, done, req, res) {
    if(err) {
        return console.error('error fetching client from pool', err);
    }
    var reqArr = [req.body.lifetime, req.body.type, req.body.netFood, req.body.posFood, req.body.negFood, req.body.members];
    var jsonQuery = "";
    var i;
    jsonQuery += "array[";
    for (i=0; i<req.body.members.length; i++) {
        jsonQuery += JSON.stringify(req.body.members[i]) + "::json";
        if (i < (req.body.members.length-1)) {
            jsonQuery += ",";
        }
    }
    jsonQuery += "]";
    reqArr[5] = jsonQuery;
    client
        //INSERT INTO "ACSchema"."Search"( "Lifetime", "Type", "Net_Food", "Pos_Food", "Neg_Food", "Members") VALUES (5, 4, 3, 2, 1, array_to_json('{{1,5},{99,100}}'::int[]));
        .query('INSERT INTO "ACSchema"."Search"("Lifetime", "Type", "Net_Food", "Pos_Food", "Neg_Food", "Members") VALUES ($1, $2, $3, $4, $5, $6)',
        //.query('INSERT INTO "ACSchema"."Search"("Lifetime", "Type", "Net_Food", "Pos_Food", "Neg_Food", "Members") VALUES (1, 1, 1, 1, 1, array[\'{"key\":"value"}\'::json,\'{"key":"value"}\'::json])',
            reqArr,
            function(err) {
                done();
                if(err) {
                    res.json({reqArr: reqArr[5]});
                    return console.error('error running query', err);
                }
                res.send(req.query);
            });
}


function clientError(err, client) {
    console.error('idle client error', err.message, err.stack)
}

module.exports = {
    create_experiment: create_experiment,
    create_generation: create_generation,
    create_entity: create_entity,
    create_environment: create_environment,
    create_simulation: create_simulation,
    clientError: clientError,
    temp: temp,
    search: search
};