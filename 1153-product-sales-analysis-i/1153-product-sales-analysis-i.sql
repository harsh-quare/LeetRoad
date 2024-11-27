# Write your MySQL query statement below

-- Using Left Join
-- SELECT product_name, year, price 
-- FROM Sales
-- LEFT JOIN Product
-- ON Sales.product_id = Product.product_id;

-- Using Right Join
-- SELECT product_name, year, price 
-- FROM Product
-- RIGHT JOIN Sales
-- ON Sales.product_id = Product.product_id;

-- Using Subquery
SELECT sub.product_name, s.year, s.price
FROM Sales as s,
(SELECT p.product_id, p.product_name
FROM Product as p) as sub
WHERE s.product_id = sub.product_id;