# Write your MySQL query statement below

-- Using Left Join
SELECT product_name, year, price 
FROM Sales
LEFT JOIN Product
ON Sales.product_id = Product.product_id;