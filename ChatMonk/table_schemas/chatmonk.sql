-- DBTYPE=SQLITE

CREATE TABLE attachment_tbl (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    message_id INTEGER,
    attachment_uri VARCHAR(255)
    , FOREIGN KEY (message_id) REFERENCES message_tbl(id)
);

CREATE TABLE friend_tbl (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    first_name VARCHAR(25),
    last_name VARCHAR(25),
    email VARCHAR(40),
    phone_number VARCHAR(15),
    photo_url VARCHAR(100),
    friend_id VARCHAR(255)
);

CREATE TABLE group_tbl (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    creator_id INTEGER NOT NULL,
    group_name VARCHAR(25),
    group_description VARCHAR(150),
    group_id VARCHAR(225),
    group_photo_uri VARCHAR(100),
    unique_id VARCHAR(255),
    activated VARCHAR(14) DEFAULT 'DE-ACTIVATED'
    , FOREIGN KEY (creator_id) REFERENCES friend_tbl(id)
);

CREATE TABLE invitation_tbl (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    group_id INTEGER NOT NULL,
    private_message VARCHAR(150),
    unique_id VARCHAR(255)
    , FOREIGN KEY (group_id) REFERENCES group_tbl(id)
);

CREATE TABLE message_tbl (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    message_data VARCHAR(500),
    sender_id VARCHAR(255),
    receiver_id VARCHAR(255)
);

