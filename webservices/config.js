/**
 * @Description: This file declares configuration variables
 * Export additional variables in module.exports at the bottom of the file
 */
// Defines pg config for DB server connection
var pg = {
    user: 'acs_server', //env var: PGUSER
    database: 'AntColony_DB', //env var: PGDATABASE
    password: 'LetsMakeAntsDoWorkForUs', //env var: PGPASSWORD
    host: '68.227.130.141', // Server hosting the postgres database
    port: 2224, //env var: PGPORT
    max: 10, // max number of clients in the pool
    idleTimeoutMillis: 30000, // how long a client is allowed to remain idle before being closed
};

module.exports = {
    pg: pg
};