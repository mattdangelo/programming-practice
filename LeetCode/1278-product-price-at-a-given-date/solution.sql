-- Get the latest prices on all products on or before the cutoff date
WITH latest_prices AS (
 SELECT p1.product_id, new_price AS price
    FROM Products p1
    JOIN (SELECT product_id, MAX(change_date) AS latest_date
            FROM Products
            WHERE change_date <= '2019-08-16'
            GROUP BY product_id) p2
    ON p1.product_id = p2.product_id AND p1.change_date = p2.latest_date),
-- Get a default price for each distinct product, in case it didn't have a price change on
-- or before the cutoff date
default_prices AS (
    SELECT DISTINCT product_id, 10 AS price
    FROM Products
)
-- Join them and coalesce the prices
SELECT default_prices.product_id, COALESCE(latest_prices.price, default_prices.price) AS price
FROM default_prices 
LEFT JOIN latest_prices ON default_prices.product_id = latest_prices.product_id
