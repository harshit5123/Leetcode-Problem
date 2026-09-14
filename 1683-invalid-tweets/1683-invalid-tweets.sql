SELECT tweet_id
FROM Tweets
WHERE tweet_id IN (
    SELECT tweet_id
    FROM Tweets
    WHERE LENGTH(content) > 15
);