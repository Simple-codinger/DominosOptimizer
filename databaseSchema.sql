PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE pizzas
(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	price REAL
);
INSERT INTO pizzas VALUES(1,'Dutchman',12.49);
INSERT INTO pizzas VALUES(2,'DanishBurgerPizza',12.99);
INSERT INTO pizzas VALUES(3,'TeriyakiChicken',13.99);
INSERT INTO pizzas VALUES(4,'CrazyDog',12.49);
INSERT INTO pizzas VALUES(5,'SucukHollandaise',13.99);
INSERT INTO pizzas VALUES(6,'Bombay',12.49);
INSERT INTO pizzas VALUES(7,'Boston',12.49);
INSERT INTO pizzas VALUES(8,'BBQPoncho',13.99);
INSERT INTO pizzas VALUES(9,'SalamiSupreme',12.49);
INSERT INTO pizzas VALUES(10,'Lucifer',12.49);
INSERT INTO pizzas VALUES(11,'Conchita',14.49);
INSERT INTO pizzas VALUES(12,'Lucca',12.49);
INSERT INTO pizzas VALUES(13,'Beef&Veggies',14.99);
INSERT INTO pizzas VALUES(14,'Steak&Bacon',14.49);
INSERT INTO pizzas VALUES(15,'FitnessFan',12.99);
INSERT INTO pizzas VALUES(16,'Salami',11.99);
INSERT INTO pizzas VALUES(17,'Margherita',11.49);
INSERT INTO pizzas VALUES(18,'Funghi',11.49);
INSERT INTO pizzas VALUES(19,'Caprese',11.49);
INSERT INTO pizzas VALUES(20,'ProsciuttoEFunghi',11.99);
INSERT INTO pizzas VALUES(21,'Tuna',12.99);
INSERT INTO pizzas VALUES(22,'Waikiki',12.49);
INSERT INTO pizzas VALUES(23,'VeggieMargherita',11.49);
INSERT INTO pizzas VALUES(24,'VeggieFunghi',11.49);
INSERT INTO pizzas VALUES(25,'VeggieCaprese',11.49);
INSERT INTO pizzas VALUES(26,'VeggieGreenGarden',12.49);
INSERT INTO pizzas VALUES(27,'VeganOhJacky',10.49);
INSERT INTO pizzas VALUES(28,'LasVega',12.99);
INSERT INTO pizzas VALUES(29,'Vegayaki',13.99);
INSERT INTO pizzas VALUES(30,'VeganCurry',13.99);
INSERT INTO pizzas VALUES(31,'KapVerdeVegan',12.49);
INSERT INTO pizzas VALUES(32,'BlankPizza',9.99);
INSERT INTO pizzas VALUES(33,'BlankPizzaVegan',8.99);

CREATE TABLE toppings
(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	price REAL
);

INSERT INTO toppings VALUES(1,'Kaese',2.29);
INSERT INTO toppings VALUES(2,'Ananas',1.59);
INSERT INTO toppings VALUES(3,'Bacon',2.09);
INSERT INTO toppings VALUES(4,'BBQSauce',1.39);
INSERT INTO toppings VALUES(5,'Brocoli',1.59);
INSERT INTO toppings VALUES(6,'Champignons',1.59);
INSERT INTO toppings VALUES(7,'Cherrytomaten',2.09);
INSERT INTO toppings VALUES(8,'Chilisalami',2.09);
INSERT INTO toppings VALUES(9,'CurrySauce',1.39);
INSERT INTO toppings VALUES(10,'GurkeDaenisch',1.59);
INSERT INTO toppings VALUES(11,'DaenischeRemoulade',1.39);
INSERT INTO toppings VALUES(12,'Fruehlingszwiebeln',1.59);
INSERT INTO toppings VALUES(13,'ItalienischerHartkaese',2.29);
INSERT INTO toppings VALUES(14,'Haenchenbrust',2.49);
INSERT INTO toppings VALUES(15,'VeganeFiletstuecke',2.49);
INSERT INTO toppings VALUES(16,'SauceHollandaise',1.39);
INSERT INTO toppings VALUES(17,'JackfruitMediterran',2.49);
INSERT INTO toppings VALUES(18,'JalapenoMix',1.59);
INSERT INTO toppings VALUES(19,'VeganerReibeschmelz',2.29);
INSERT INTO toppings VALUES(20,'TomatenKetchup',1.39);
INSERT INTO toppings VALUES(21,'KnoblauchInÖl',0.39);
INSERT INTO toppings VALUES(22,'Mais',1.59);
INSERT INTO toppings VALUES(23,'MediterranesGemuese',2.09);
INSERT INTO toppings VALUES(24,'MozzarellaKugeln',2.29);
INSERT INTO toppings VALUES(25,'Paprika',1.59);
INSERT INTO toppings VALUES(26,'PizzaChlilis',0);
INSERT INTO toppings VALUES(27,'BasilikumPesto',1.39);
INSERT INTO toppings VALUES(28,'ProsciuttoCotto',2.09);
INSERT INTO toppings VALUES(29,'Rinderhack',2.09);
INSERT INTO toppings VALUES(30,'RindersteakStreifen',2.49);
INSERT INTO toppings VALUES(31,'Salami',2.09);
INSERT INTO toppings VALUES(32,'VeganSalami',2.49);
INSERT INTO toppings VALUES(33,'Sesam',0);
INSERT INTO toppings VALUES(34,'Blattspinat',1.59);
INSERT INTO toppings VALUES(35,'Steakpfeffer',0);
INSERT INTO toppings VALUES(36,'Sucuk',2.09);
INSERT INTO toppings VALUES(37,'TeriyakiSauceVegan',1.39);
INSERT INTO toppings VALUES(38,'Thunfisch',2.49);
INSERT INTO toppings VALUES(39,'Tomaten',1.59);
INSERT INTO toppings VALUES(40,'Wuerstchen',2.09);
INSERT INTO toppings VALUES(41,'Roestzwiebeln',1.59);
INSERT INTO toppings VALUES(42,'ZwiebelnRot',1.59);

CREATE TABLE pizzaToppings
(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	pizzaId INT,
	topingId INT,
	FOREIGN KEY (topingId) REFERENCES toppings(id),
	FOREIGN KEY (pizzaId) REFERENCES pizzas(id)
);
--Dutchman
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(1,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(1,16);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(1,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(1,28);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(1,39);

--DanishBurgerPizza
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,10);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,11);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,29);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,39);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(2,42);

--TeriyakiChicken
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,12);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,14);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,33);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(3,37);

--CrazyDog
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,10);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,11);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,20);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,40);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(4,41);

--SucukHollandaise
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(5,16);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(5,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(5,36);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(5,39);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(5,42);

--Bombay
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(6,2);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(6,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(6,9);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(6,14);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(6,1);

--Boston
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(7,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(7,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(7,28);

--BBQPoncho
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(8,14);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(8,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(8,22);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(8,25);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(8,42);

--SalamiSupreme
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(9,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(9,31);

--Lucifer
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(10,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(10,8);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(10,18);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(10,1);

--Conchita
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(11,3);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(11,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(11,24);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(11,29);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(11,42);

--Lucca
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(12,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(12,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(12,28);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(12,31);

--Beef&Veggies
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,16);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,23);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,30);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,35);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(13,39);

--Steak&Bacon
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,3);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,12);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,16);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,30);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(14,39);

--FitnessFan
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,14);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,25);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,39);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(15,42);

--Salami
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(16,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(16,31);

--Margherita
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(17,1);

--Funghi
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(18,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(18,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(18,27);

--Caprese
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(19,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(19,24);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(19,27);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(19,39);

--ProsciuttoEFunghi
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(20,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(20,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(20,28);

--Tuna
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(21,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(21,38);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(21,42);

--Waikiki
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(22,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(22,2);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(22,28);

--Margherita
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(23,1);

--Funghi
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(24,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(24,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(24,27);

--Caprese
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(25,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(25,24);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(25,27);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(25,39);

--GruenerGarten
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,7);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,1);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,25);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(26,34);

--OhJacky
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(27,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(27,7);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(27,17);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(27,19);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(27,22);

--LasVegas
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(28,19);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(28,21);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(28,32);

--Vegayaki
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,12);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,15);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,19);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,33);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(29,37);

--VeganCurry
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,9);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,15);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,19);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,22);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,25);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(30,42);

--KapVerde
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(31,5);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(31,6);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(31,19);
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(31,39);

--Blank
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(32,1);

--VeganBlank
INSERT INTO pizzaToppings (pizzaId, topingId) VALUES(33,19);
COMMIT;
