# Ant Colony Evolution PostgresSQL Database

## To have a local instance of the DB
1. [Install pgAdmin][]
2. Refer to `config.js` when setting the server variables.
3. Right click on `Databases`, and create a new database `AntColony_DB`. (The DB name in `config.js` is AntColony_DB)
4. Right click on `AntColony_DB`, and click `Restore`. The file type is "Custom or Tar" and paste the file path to the backup.
5. Right click on the database to refresh if the restored schema did not show up.
6. Note on remotely connecting on the DB server. This [link](http://www.thegeekstuff.com/2014/02/enable-remote-postgresql-connection/?utm_source=tuicool) was useful on a mac.

[Install pgAdmin]: https://www.pgadmin.org
