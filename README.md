2.10 + 2.00 + 1.00 + 1.00

CREATE TABLE Object(
	id BIGSERIAL PRIMARY KEY,
	name text,
	coordinate_X double precision,
	coordinate_Y double precision,
	type text,
	creationTime double precision
);

CREATE TABLE Car(
	id BIGSERIAL PRIMARY KEY,
	obj_id integer REFERENCES Object(id),
	maxSpeed integer
);

CREATE TABLE Human(
	id BIGSERIAL PRIMARY KEY,
	obj_id integer REFERENCES Object(id),
	surname text
);

INSERT INTO Object (name, coordinate_X, coordinate_Y, type, creationTime) VALUES
('Curved', -37.23, 13.44, 'Human', 1693235249.98678),
('Shop', 0.163, 2.119, 'Building', 1693135218.173),
('Lada', 118.3, -982.041, 'Car', 1692748121.63),
('RepairShop', 23.11, -11.67, 'Building', 1692638921.431),
('School', 56.982, 90.111, 'Building', 1692391002.988),
('Bus', -10.7, 103.4, 'Car', 1692281345.127),
('Office', 31.6, -27.11, 'Building', 1692115612.003),
('Pedestrian', -5.76, 20.45, 'Human', 1691982743.621),
('Cyclist', 40.22, 12.98, 'Human', 1691809632.786),
('Park', -18.98, 7.32, 'Building', 1691675210.241),
('Motorcycle', 250.12, -320.65, 'Car', 1691541203.829),
('Driver', -12.45, 55.67, 'Human', 1691385438.777),
('Mall', 33.91, -15.03, 'Building', 1691201012.004),
('Truck', -20.18, 100.31, 'Car', 1691044512.444);

INSERT INTO Human (obj_id, surname) VALUES
(1, 'Petrov'),     
(8, 'Ivanov'),     
(9, 'Sidorov'),    
(12, 'Kuznetsov'); 

INSERT INTO Car (obj_id, maxSpeed) VALUES
(3, 180), 
(6, 100),
(11, 120),
(14, 80); 

select obj.id, obj.name, obj.coordinate_x, obj.coordinate_y, obj.type, obj.creationtime, car.maxspeed, hum.surname
from object obj
Left Join car on obj.id = car.obj_id
Left Join human hum on obj.id = hum.obj_id
