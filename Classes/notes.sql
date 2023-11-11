
relational database = database program (running on computer w/ a lot of memory), can have many datasheets across with relationships
SQL = structured query language, -> database specific language, describes the data i want to get back
-> CRUD = Create (insert), Read (select), Update, Delete (drop)

sqlite3 = lite version of SQL

# essentially same as creating a spreadsheet
CREATE TABLE table_name (column type, ...);
sqlite3 FILE_NAME
.mode csv  # set to csv mode
.import filename.csv table_name
.schema # shows the data in the database
SELECT column_name FROM table_name LIMIT 10; # only show 10 data
SELECT COUNT(*) FROM table_name; # * means to show everything
SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC; # shows the counts for each favorite language

INSERT INTO table_name (column_name, ...) VALUES(value_name, ...);
# column_name = name of column i want to put value into, values = value name (basically adding new row)
NULL = no data there
DELETE FROM table_name WHERE condition;
UPDATE table_name SET column = value WHERE condition;

functions:
AVG
COUNT
DISTINCT
LOWER
MAX
MIN
UPPER
WHERE
LIKE
ORDER BY
LIMIT
GROUP BY
NOT NULL = cannot enter null value
UNIQUE = has to be unique, no duplicate
IS
AND
JOIN = join 2 tables

datatypes:
BLOB = binary large object = file w 0s and 1s
INTEGER
NUMERIC = dates, times (but not necessarily numbers)
REAL = have decimal points
TEXT
PRIMARY KEY = unique integer that identifies each data set
FOREIGN KEY = in key but not created in them, primary keys in another table

one-to-one = every x has one y
one-to-many = every x can have multiple y
many-to-many = multiple x can have multiple y
-> when many-to-many, need a third table to bridge the two together
can have nested queries -> put one inside the other

SELECT * shows WHERE id IN (SELECT show_id FROM ratings WHERE rating >= 6.0) # nested query
SELECT title, rating FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating >= 6.0 LIMIT 10; # titles & rating as a table

if join 2 tables, will have duplication for rows with less "info" than others when joining

SELECT title FROM shows WHERE id IN
 (SELECT show_id FROM stars WHERE person_id =
  (SELECT id FROM people WHERE name = 'Steve Carell'));

SELECT title FROM shows
JOIN stars ON shows.id = stars.show_id
JOIN people ON stars.person_id = people.id
WHERE name = 'Steve Carell';

SELECT title FROM shows, stars, people
WHERE shows.id = stars.show_id
AND people.id = stars.person_id
AND name = 'Steve Carell';

indexes = data structure that makes it faster to perform queries

CREATE INDEX name ON table (column, ...);
CREATE INDEX show_index ON stars (show_id);
B-trees = every node has multiple children
-> shorter tree = shorter leaves
-> created in index
-> trade-off = more memory

primary keys = indexes
race conditions = order matters when we care;
-> state of variable was about to be updated while it was being looked at

from cs50 import SQL

db = SQL("sqlite:///favorites.db")
favorite = input("Favorite: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
row = rows[0]

print(row["n"])


race conditions code
BEGIN TRANSACTION -> lines of code either happen together or dont happen at all (atomic)
COMMIT
ROLLBACK

db.execute("BEGIN TRANSACTION")
rows = db.execute("SELECT likes FROM posts WHERE id = ?", id)
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes+1, id)
db.executive("COMMIT")


sql injection attack = code too vulnerable to being hacked



--

router = send info from point a to point b
internet = can route across/down servers -> dynamic
packet = generic name for information
TCP/IP = 2 protocols that the internet uses to get data from point a to b
IP = internet protocol = standardizes how the addresses work
--> every computer/internet device has a IP address (unique string that identifies computers)
--> #.#.#.# -- each number is between 0 and 255; so 8 bits/1 byte per number; 2^32 = 4 billion unique numbers
--> provides source and destination address

TCP = pair of protocols that gets us from point a to b, guarantees delivery via writing a sequence number, helps servers do more than one thing
--> gives us port numbers
--> common port numbers: 80 (HTTP), 443 (HTTPS, secure version of HTTP)
--> sequence numbers are really big (using up all 32 bits)

domain names = wix.com
DNS = domain-name-system servers
--> answers what ip address is for the domain name (numeric address)
--> dictionary: fully qualified domain name (key) -> ip address (values)
--> ask local, then bigger, then eventually root systems

DHCP = dynamic host configuration protocol
--> what should be by DNS server and router?
--> HTTP = worldwide web = protocol that governs how web browsers and servers speak
--> for web, standardizes what goes inside the envelope
--> HTTP = hyper text transfer protocol

HTTPS = secure version of HTTP (secure version that prevents interceptors)
https://www.example.com/path --> something a page inside
                   ^ / = root, default page/folder for website
https://www.example.com/folder/file.html --> file, usually doesn't have html there
         ^ full domain name, includes www
         ^ www = host name

