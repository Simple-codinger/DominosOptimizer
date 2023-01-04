CREATE TABLE pizzas
(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	price REAL
);

CREATE TABLE toppings
(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	price REAL
);

CREATE TABLE pizzaToppings
(
	id int PRIMARY KEY,
	toppingsId INT,
	pizzasId INT,
	FOREIGN KEY (toppingsId) REFERENCES toppings(id),
	FOREIGN KEY (pizzasId) REFERENCES pizzas(id)
);
