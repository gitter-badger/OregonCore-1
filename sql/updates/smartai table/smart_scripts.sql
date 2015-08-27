/*
SQLyog Community v12.12 (64 bit)
MySQL - 5.6.26-log 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

create table `smart_scripts` (
	`entryorguid` int (11),
	`source_type` tinyint (3),
	`id` smallint (5),
	`link` smallint (5),
	`event_type` tinyint (3),
	`event_phase_mask` tinyint (3),
	`event_chance` tinyint (3),
	`event_flags` tinyint (3),
	`event_param1` int (10),
	`event_param2` int (10),
	`event_param3` int (10),
	`event_param4` int (10),
	`action_type` tinyint (3),
	`action_param1` int (10),
	`action_param2` int (10),
	`action_param3` int (10),
	`action_param4` int (10),
	`action_param5` int (10),
	`action_param6` int (10),
	`target_type` tinyint (3),
	`target_param1` int (10),
	`target_param2` int (10),
	`target_param3` int (10),
	`target_x` float ,
	`target_y` float ,
	`target_z` float ,
	`target_o` float ,
	`comment` text 
); 
