/*
Navicat MySQL Data Transfer

Source Server         : Ming_Ab
Source Server Version : 50721
Source Host           : 127.0.0.1:3306
Source Database       : grademanager

Target Server Type    : MYSQL
Target Server Version : 50721
File Encoding         : 65001

Date: 2019-06-02 00:28:42
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for allpassword
-- ----------------------------
DROP TABLE IF EXISTS `allpassword`;
CREATE TABLE `allpassword` (
  `user` char(7) NOT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`user`),
  CONSTRAINT `paswd_stu` FOREIGN KEY (`user`) REFERENCES `student` (`Sno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of allpassword
-- ----------------------------
INSERT INTO `allpassword` VALUES ('2000101', '123456');
INSERT INTO `allpassword` VALUES ('2000102', '123456');
INSERT INTO `allpassword` VALUES ('2000103', '123456');
INSERT INTO `allpassword` VALUES ('2000104', '123456');
INSERT INTO `allpassword` VALUES ('2001101', '123456');
INSERT INTO `allpassword` VALUES ('2001102', '123456');
INSERT INTO `allpassword` VALUES ('2001103', '123456');
INSERT INTO `allpassword` VALUES ('2001104', '123456');

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `Cno` char(2) NOT NULL,
  `Cname` varchar(20) NOT NULL,
  `Credit` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`Cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('1', '数据库', '4');
INSERT INTO `course` VALUES ('2', '离散数学', '3');
INSERT INTO `course` VALUES ('3', '管理信息系统', '3');
INSERT INTO `course` VALUES ('4', '操作系统', '4');
INSERT INTO `course` VALUES ('5', '数据结构', '4');
INSERT INTO `course` VALUES ('6', '数据处理', '2');
INSERT INTO `course` VALUES ('7', 'C语言', '4');

-- ----------------------------
-- Table structure for grade
-- ----------------------------
DROP TABLE IF EXISTS `grade`;
CREATE TABLE `grade` (
  `Sno` char(7) NOT NULL,
  `Cno` char(2) NOT NULL,
  `Gmark` decimal(4,1) DEFAULT NULL,
  KEY `Sno` (`Sno`),
  KEY `cno_tocourse` (`Cno`),
  CONSTRAINT `cno_tocourse` FOREIGN KEY (`Cno`) REFERENCES `course` (`Cno`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sno_tostudent` FOREIGN KEY (`Sno`) REFERENCES `student` (`Sno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of grade
-- ----------------------------
INSERT INTO `grade` VALUES ('2000101', '1', '92.0');
INSERT INTO `grade` VALUES ('2000101', '3', null);
INSERT INTO `grade` VALUES ('2000101', '5', '86.0');
INSERT INTO `grade` VALUES ('2000102', '1', '78.0');
INSERT INTO `grade` VALUES ('2000102', '6', '55.0');
INSERT INTO `grade` VALUES ('2000103', '3', '65.0');
INSERT INTO `grade` VALUES ('2000103', '6', '78.0');
INSERT INTO `grade` VALUES ('2000103', '5', '66.0');
INSERT INTO `grade` VALUES ('2000104', '1', '54.0');
INSERT INTO `grade` VALUES ('2000104', '6', '83.0');
INSERT INTO `grade` VALUES ('2001101', '2', '70.0');
INSERT INTO `grade` VALUES ('2001101', '4', '65.0');
INSERT INTO `grade` VALUES ('2001102', '2', '80.0');
INSERT INTO `grade` VALUES ('2001102', '4', null);
INSERT INTO `grade` VALUES ('2000103', '1', '83.0');
INSERT INTO `grade` VALUES ('2000103', '2', '76.0');
INSERT INTO `grade` VALUES ('2000103', '4', '56.0');
INSERT INTO `grade` VALUES ('2000103', '7', '88.0');

-- ----------------------------
-- Table structure for retake
-- ----------------------------
DROP TABLE IF EXISTS `retake`;
CREATE TABLE `retake` (
  `Sno` char(7) NOT NULL,
  `Cno` char(2) NOT NULL,
  `retake` char(2) DEFAULT '否',
  KEY `sno_tograde` (`Sno`),
  CONSTRAINT `sno_tograde` FOREIGN KEY (`Sno`) REFERENCES `grade` (`Sno`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of retake
-- ----------------------------
INSERT INTO `retake` VALUES ('2000102', '6', '否');
INSERT INTO `retake` VALUES ('2000104', '1', '否');
INSERT INTO `retake` VALUES ('2001102', '4', '否');
INSERT INTO `retake` VALUES ('2000103', '4', '否');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `Sno` char(7) NOT NULL,
  `Sname` varchar(19) DEFAULT NULL,
  `Ssex` char(2) NOT NULL,
  `Sage` smallint(6) DEFAULT NULL,
  `Clno` char(5) NOT NULL,
  PRIMARY KEY (`Sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('2000101', '李勇', '男', '20', '00311');
INSERT INTO `student` VALUES ('2000102', '刘诗晨', '女', '19', '00311');
INSERT INTO `student` VALUES ('2000103', '王一鸣', '男', '20', '00312');
INSERT INTO `student` VALUES ('2000104', '张婷婷', '女', '21', '00312');
INSERT INTO `student` VALUES ('2001101', '李勇敏', '女', '19', '01311');
INSERT INTO `student` VALUES ('2001102', '贾向东', '男', '22', '01311');
INSERT INTO `student` VALUES ('2001103', '陈宝玉', '男', '20', '01311');
INSERT INTO `student` VALUES ('2001104', '张逸凡', '男', '21', '01311');
DROP TRIGGER IF EXISTS `c_grade_retake`;
DELIMITER ;;
CREATE TRIGGER `c_grade_retake` AFTER INSERT ON `grade` FOR EACH ROW begin
if NEW.gmark<60 then
insert into retake(sno,cno) values (NEW.sno,NEW.cno);
end if;
end
;;
DELIMITER ;
DROP TRIGGER IF EXISTS `c_stu_pswd`;
DELIMITER ;;
CREATE TRIGGER `c_stu_pswd` AFTER INSERT ON `student` FOR EACH ROW BEGIN
INSERT INTO allpassword(user) VALUES (new.Sno);
END
;;
DELIMITER ;
