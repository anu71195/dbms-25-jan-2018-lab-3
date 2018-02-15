create database 25jan2018;
use 25jan2018;
create table ett(
	course_id CHAR(10)  COMMENT "course_id contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set" ,
	exam_date DATE  COMMENT "Date is define in the format accepted by sql which is YYYY-MM-DD format so usin defualt DATE datatype from mysql is the safest option",
	start_time TIME NOT NULL COMMENT "if there is an examination so it should have some start time. Though the time is given in HH:MM format the one which is accepted by mysql is HH:MM:SS but with c we can write it as HH:MM:00 to meet the mysql requirements and hence the format",
	end_time TIME NOT NULL COMMENT "if there is an examination and it has some start time so it should have some end time too Though the time is given in HH:MM format the one which is accepted by mysql is HH:MM:SS but with c we can write it as HH:MM:00 to meet the mysql requirements and hence the format",
	CONSTRAINT Time_Table PRIMARY KEY(course_id,exam_date) COMMENT "for every course id given in the list there is a unique exam_date... same exam can't occur twice in a day"
);
create table cc(
	course_id CHAR(10) COMMENT "course_id contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set" , 
	number_of_credits INT NOT NULL COMMENT "if a course is mentioned then it should have some credits associated with it so it can't be null,INT can take values up to 2147483647 and the number_of_credits has no value greater than 10 so INT can accomodate all the credit values",
	CONSTRAINT Course_Credit PRIMARY KEY(course_id)	COMMENT "course id is unique so it is the primary key",
	CONSTRAINT Unique_cc_id UNIQUE (course_id) COMMENT "each course will have some credits totalled up and so same course should not occur twice telling about its credit"

);

create table cwsl(
	cid CHAR(10) COMMENT "cid contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set",
	serial_number INT NOT NULL AUTO_INCREMENT COMMENT "INT can take values up to 2147483647 and the serial number can be maximum of no of students within IITG which is less than 2147483647 so INT can be used safely and it can't be null ",
	roll_number INT COMMENT "INT can take values up to 2147483647 and the roll number of students is a 9 digit number which is less than 2147483647 and therefore all the role numbers can be accomodated in this datatype",
	name VARCHAR(100) NOT NULL COMMENT "the name of students can be as shorter than 10 characters and can be as large as 50 characters or more therefore VARCHAR can take variable length string so it is perfect for this case if the student's roll number is mentioned then he should also have some name",
	email VARCHAR(100) COMMENT "the email of students can be as shorter than 10 characters excluding @ symbol and domain name and can be as large as 50 characters or more therefore VARCHAR can take variable length string so it is perfect for this case",
	CONSTRAINT Unique_serial_number UNIQUE(serial_number) COMMENT "serial number is auto increment so it is unique",	
	CONSTRAINT Course_Wise_Student_List PRIMARY KEY(roll_number,cid) COMMENT "For every student mentioned in the list there will always be some unique course associated with that student"


);

CREATE TEMPORARY TABLE ett_temp(
	course_id CHAR(10)  COMMENT "course_id contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set" ,
	exam_date DATE  COMMENT "Date is define in the format accepted by sql which is YYYY-MM-DD format so usin defualt DATE datatype from mysql is the safest option",
	start_time TIME NOT NULL COMMENT "if there is an examination so it should have some start time. Though the time is given in HH:MM format the one which is accepted by mysql is HH:MM:SS but with c we can write it as HH:MM:00 to meet the mysql requirements and hence the format",
	end_time TIME NOT NULL COMMENT "if there is an examination and it has some start time so it should have some end time too Though the time is given in HH:MM format the one which is accepted by mysql is HH:MM:SS but with c we can write it as HH:MM:00 to meet the mysql requirements and hence the format",
	CONSTRAINT Time_Table PRIMARY KEY(course_id,exam_date) COMMENT "for every course id given in the list there is a unique exam_date... same exam can't occur twice in a day"
);
CREATE TEMPORARY TABLE cc_temp(
	course_id CHAR(10) COMMENT "course_id contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set" , 
	number_of_credits INT NOT NULL COMMENT "if a course is mentioned then it should have some credits associated with it so it can't be null,INT can take values up to 2147483647 and the number_of_credits has no value greater than 10 so INT can accomodate all the credit values",
	CONSTRAINT Course_Credit PRIMARY KEY(course_id)	COMMENT "course id is unique so it is the primary key",
	CONSTRAINT Unique_cc_id UNIQUE (course_id) COMMENT "each course will have some credits totalled up and so same course should not occur twice telling about its credit"

);
CREATE TEMPORARY TABLE cwsl_temp(
	cid CHAR(10) COMMENT "cid contains both numbers and characters of maximum length of 6 so it is best to store it in string so just to be safe length of 10 is set",
	serial_number INT NOT NULL AUTO_INCREMENT COMMENT "INT can take values up to 2147483647 and the serial number can be maximum of no of students within IITG which is less than 2147483647 so INT can be used safely and it can't be null ",
	roll_number INT COMMENT "INT can take values up to 2147483647 and the roll number of students is a 9 digit number which is less than 2147483647 and therefore all the role numbers can be accomodated in this datatype",
	name VARCHAR(100) NOT NULL COMMENT "the name of students can be as shorter than 10 characters and can be as large as 50 characters or more therefore VARCHAR can take variable length string so it is perfect for this case, if the student's roll number is mentioned then he should also have some name",
	email VARCHAR(100) COMMENT "the email of students can be as shorter than 10 characters excluding @ symbol and domain name and can be as large as 50 characters or more therefore VARCHAR can take variable length string so it is perfect for this case",
	CONSTRAINT Unique_serial_number UNIQUE(serial_number) COMMENT "serial number is auto increment so it is unique",	
	CONSTRAINT Course_Wise_Student_List PRIMARY KEY(roll_number,cid) COMMENT "For every student mentioned in the list there will always be some unique course associated with that student"

);

CREATE TABLE ett_clone LIKE ett;
CREATE TABLE cc_clone LIKE cc;
CREATE TABLE cwsl_clone LIKE cwsl;

