-- list the names of the top 5 longest songs, in descending
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;