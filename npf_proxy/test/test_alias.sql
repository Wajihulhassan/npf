SELECT CustomerName AS Customer, ContactName AS Contact FROM Customers;
SELECT CustomerName, CONCAT(Address,', ',City,', ',PostalCode,', ',Country) AS Address FROM Customers;
SELECT o.OrderID, o.OrderDate, c.CustomerName FROM Customers AS c, Orders AS o WHERE c.CustomerName="Around the Horn" AND c.CustomerID=o.CustomerID;