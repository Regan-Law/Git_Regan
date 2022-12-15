-- MySQL
--
-- Host: localhost    Database: python
-- ------------------------------------------------------


 SET NAMES utf8mb4 ;


--
-- Table structure for table `grade`
--

DROP TABLE IF EXISTS `grade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `grade` (
  `num` varchar(20) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `class` varchar(20) NOT NULL,
  `course1` double(5,2) DEFAULT '-1.00',
  `course2` double(5,2) DEFAULT '-1.00',
  `course3` double(5,2) DEFAULT '-1.00',
  `sum` double(5,2) DEFAULT '0.00',
  PRIMARY KEY (`num`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grade`
--

LOCK TABLES `grade` WRITE;
/*!40000 ALTER TABLE `grade` DISABLE KEYS */;
INSERT INTO `grade` VALUES ('101', '周静', '软工三班', '70.00', '80.00', '90.00', '240.00', '1', '2', '2022-12-02 00:00:00');
INSERT INTO `grade` VALUES ('102', '周婷婷', '软工三班', '80.00', '90.00', '50.00', '220.00', '0', '0', null);
INSERT INTO `grade` VALUES ('103', '邓少苗', '软工三班', '90.00', '50.00', '80.00', '220.00', '0', '0', null);
INSERT INTO `grade` VALUES ('104', '吴露露', '软工一班', '40.00', '80.00', '100.00', '220.00', '0', '0', null);
INSERT INTO `grade` VALUES ('105', '小明', '软工一班', '55.00', '45.00', '70.00', '170.00', '0', '0', null);
INSERT INTO `grade` VALUES ('106', '赵四', '软工一班', '40.00', '60.00', '80.00', '180.00', '1', '2', '2022-12-02 00:00:00');
/*!40000 ALTER TABLE `grade` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `root`
--

DROP TABLE IF EXISTS `root`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `root` (
  `username` varchar(15) NOT NULL,
  `password` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `root`
--

LOCK TABLES `root` WRITE;
/*!40000 ALTER TABLE `root` DISABLE KEYS */;
INSERT INTO `root` VALUES ('root','123'),('root1','123');
/*!40000 ALTER TABLE `root` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stud`
--

DROP TABLE IF EXISTS `stud`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `stud` (
  `username` varchar(15) NOT NULL,
  `name` varchar(30) NOT NULL,
  `pass` varchar(30) NOT NULL,
  PRIMARY KEY (`username`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stud`
--

LOCK TABLES `stud` WRITE;
/*!40000 ALTER TABLE `stud` DISABLE KEYS */;
/*!40000 ALTER TABLE `stud` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student` (
  `username` varchar(20) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES ('101', '周静', '1234');
INSERT INTO `student` VALUES ('102', '周婷婷', '123');
INSERT INTO `student` VALUES ('103', '吴露露', '123');
INSERT INTO `student` VALUES ('104', '邓少苗', '123');
INSERT INTO `student` VALUES ('105', '小明', '123');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `teacher` (
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teacher`
--

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES ('teacher','123'),('teacher1','1234'),('teacher2','123'),('teacher3','123');
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `up`
--

DROP TABLE IF EXISTS `up`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `up` (
  `sno` varchar(15) NOT NULL,
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `up`
--

LOCK TABLES `up` WRITE;
/*!40000 ALTER TABLE `up` DISABLE KEYS */;
/*!40000 ALTER TABLE `up` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

