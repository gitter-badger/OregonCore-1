-- Set proper required classes for Dire Maul book quests
UPDATE `quest_template` SET `RequiredClasses` = 1 WHERE `entry` = 7499; -- Codex of Defense (18357/7499)
UPDATE `quest_template` SET `RequiredClasses` = 2 WHERE `entry` = 7501; -- The Light and How to Swing It (18359/7501)
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `entry` = 7503; -- The Greatest Race of Hunters (18361/7503)
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `entry` = 7498; -- Garona: A Study on Stealth and Treachery (18356/7498)
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `entry` = 7504; -- Holy Bologna: What the Light Won't Tell You (18362/7504)
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `entry` = 7505; -- Frost Shock and You (18363/7505) Closes #4727
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `entry` = 7500; -- The Arcanist's Cookbook (18358/7500)
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `entry` = 7502; -- Harnessing Shadows (18360/7502)
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `entry` = 7506; -- The Emerald Dream... (18364/7506)

-- Nether Stalker Mah'duun: non-heroic dungeon daily pool
SET @nh_daily_pool := 20200;

DELETE FROM `pool_template` WHERE `entry` = @nh_daily_pool;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@nh_daily_pool, '1', 'Quest Pool: Nether-Stalker Mah\'duun');

DELETE FROM `pool_quest` WHERE `pool_entry` = @nh_daily_pool AND `entry` IN (11389, 11371, 11376, 11383, 11364, 11500, 11385, 11387);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
('11389', @nh_daily_pool, 'Wanted: Arcatraz Sentinels'),
('11371', @nh_daily_pool, 'Wanted: Coilfang Myrmidons'),
('11376', @nh_daily_pool, 'Wanted: Malicious Instructors'),
('11383', @nh_daily_pool, 'Wanted: Rift Lords'),
('11364', @nh_daily_pool, 'Wanted: Shattered Hand Centurions'),
('11500', @nh_daily_pool, 'Wanted: Sisters of Torment'),
('11385', @nh_daily_pool, 'Wanted: Sunseeker Channelers'),
('11387', @nh_daily_pool, 'Wanted: Tempest-Forge Destroyers');

-- Wind Trader Zhareem: heroic dungeon daily pool
SET @hc_daily_pool := 20201;

DELETE FROM `pool_template` WHERE `entry` = @hc_daily_pool;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@hc_daily_pool, '1', 'Quest Pool: Wind Trader Zhareem');

DELETE FROM `pool_quest` WHERE `pool_entry` = @hc_daily_pool AND `entry` IN (11369, 11384, 11382, 11363, 11362, 11375, 11354, 11386, 11373, 11378, 11374, 11372, 11368, 11388, 11499, 11370);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
('11369', @hc_daily_pool, 'Wanted: A Black Stalker Egg'),
('11384', @hc_daily_pool, 'Wanted: A Warp Splinter Clipping'),
('11382', @hc_daily_pool, 'Wanted: Aeonus\'s Hourglass'),
('11363', @hc_daily_pool, 'Wanted: Bladefist\'s Seal'),
('11362', @hc_daily_pool, 'Wanted: Keli\'dan\'s Feathered Stave'),
('11375', @hc_daily_pool, 'Wanted: Murmur\'s Whisper'),
('11354', @hc_daily_pool, 'Wanted: Nazan\'s Riding Crop'),
('11386', @hc_daily_pool, 'Wanted: Pathaleon\'s Projector'),
('11373', @hc_daily_pool, 'Wanted: Shaffar\'s Wondrous Pendant'),
('11378', @hc_daily_pool, 'Wanted: The Epoch Hunter\'s Head'),
('11374', @hc_daily_pool, 'Wanted: The Exarch\'s Soul Gem'),
('11372', @hc_daily_pool, 'Wanted: The Headfeathers of Ikiss'),
('11368', @hc_daily_pool, 'Wanted: The Heart of Quagmirran'),
('11388', @hc_daily_pool, 'Wanted: The Scroll of Skyriss'),
('11499', @hc_daily_pool, 'Wanted: The Signet Ring of Prince Kael\'thas'),
('11370', @hc_daily_pool, 'Wanted: The Warlord\'s Treatise');

-- Shattrath Cooking Daily Pool
-- 11380, 11377, 11379, 11381
SET @pool := 11377;

DELETE FROM `pool_template` WHERE `entry` = @pool;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool, 1, 'Shattrath Cooking Daily (1 of 4)');

DELETE FROM `pool_quest` WHERE `entry` IN (11380, 11377, 11379, 11381) AND `pool_entry` = @pool;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(11380, @pool, 'Manalicious'),
(11377, @pool, 'Revenge is Tasty'),
(11381, @pool, 'Soup for the Soul'),
(11379, @pool, 'Super Hot Stew');

-- Shattrath Fishing Daily Pool
-- 11667, 11668, 11666, 11665, 11669
SET @pool := 11665;

DELETE FROM `pool_template` WHERE `entry` = @pool;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool, 1, 'Shattrath Fishing Daily (1 of 5)');

DELETE FROM `pool_quest` WHERE `entry` IN (11667, 11668, 11666, 11665, 11669) AND `pool_entry` = @pool;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(11667, @pool, 'The One That Got Away'),
(11668, @pool, 'Shrimpin\' Ain\'t Easy'),
(11666, @pool, 'Bait Bandits'),
(11665, @pool, 'Crocolisks in the City'),
(11669, @pool, 'Felblood Filet');

-- areatrigger_teleport fixes
UPDATE `areatrigger_teleport` SET `target_orientation`= 3.30496 WHERE `id`=922;
UPDATE `areatrigger_teleport` SET `target_orientation`=4.718671 WHERE `id`=3928; -- Zul Gurub entrance
UPDATE `areatrigger_teleport` SET `target_orientation`=1.617921 WHERE `id`=3930; -- Zul Gurub exit
UPDATE `areatrigger_teleport` SET `target_orientation`=4.582802 WHERE `id`=259; -- Blackfathom deeps
UPDATE `areatrigger_teleport` SET `target_orientation`=3.147877 WHERE `id`=3186; -- Dire Maul, Capital Gardens, south
UPDATE `areatrigger_teleport` SET `target_orientation`=1.784425 WHERE `id`=3126; -- Maraudon, north
UPDATE `areatrigger_teleport` SET `target_position_z`=81.491974, `target_orientation`='1.259779' WHERE `id`=444; -- Razorfen Downs
UPDATE `areatrigger_teleport` SET `target_orientation`=1.840974 WHERE `id`=1472; -- Blackrock Dephts
UPDATE `areatrigger_teleport` SET `target_orientation`=2.095443 WHERE `id`=1470; -- Blackrock Spire
UPDATE `areatrigger_teleport` SET `target_orientation`=3.663096 WHERE `id`=2568; -- Scholomance
UPDATE `areatrigger_teleport` SET `target_position_z`=108.449623, `target_orientation`=1.935219 WHERE `id`=2221; -- Stratholme
UPDATE `areatrigger_teleport` SET `target_orientation`=4.55217 WHERE `id`=119; -- Deadmines
UPDATE `areatrigger_teleport` SET `target_orientation`=3.20443 WHERE `id`=288; -- Uldaman, north
UPDATE `areatrigger_teleport` SET `target_position_z`=266.22583, `target_orientation`=3.135308 WHERE `id`=882; -- Uldaman, south
UPDATE `areatrigger_teleport` SET `target_orientation`=2.959382 WHERE `id`=448; -- Altar of Atal'Hakkar

-- Spawning and Pooling of Outland Rare Mobs
-- create missing spawns:
SET @GUID := 151895;

DELETE FROM `creature` WHERE `id`IN(18695,18697,18689,18686,18698,18678,17144,18692,18677,18693,18683,18679);
INSERT INTO creature
(`guid`,`id`,`map`,`spawnMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`)
VALUES
-- Ambassador Jerrikar
(@GUID,18695,530,1,0,0,-4455.05,1694.55,161.278,1.93093,28800,0,0,13522,0,0,0),
(@GUID+1,18695,530,1,0,0,-4203.43,344.462,115.416,4.161,28800,0,0,13522,0,0,0),
(@GUID+2,18695,530,1,0,0,-3815.24,2689.31,100.581,5.38433,28800,5,0,13522,0,0,1),
(@GUID+3,18695,530,1,0,0,-3082.38,1867.38,139.906,1.53194,28800,5,0,13522,0,0,1),
(@GUID+4,18695,530,1,0,0,-3076.35,1020.61,-2.88056,3.73969,28800,5,0,13522,0,0,1),
-- Chief Engineer Lorthander
(@GUID+5,18697,530,1,0,0,4092.53,4001.75,117.282,4.650480,28800,0,0,10818,15400,0,0),
(@GUID+6,18697,530,1,0,0,2293.31,2821.12,130.917,4.422730,28800,5,0,10818,15400,0,1),
(@GUID+7,18697,530,1,0,0,2954.82,2147.42,165.328,0.753333,28800,5,0,10818,15400,0,1),
-- Crippler
(@GUID+8,18689,530,1,0,0,-3005.68,5037.76,-23.7032,4.12334,28800,30,0,11828,0,0,1), -- only have one for him :(
-- Doomsayer Jurim
(@GUID+9,18686,530,1,0,0,-2537.44,5147.04,9.05971,5.82974,28800,0,0,9144,13525,0,0),
(@GUID+10,18686,530,1,0,0,-1874.09,4663.57,10.9095,3.87017,28800,5,0,9144,13525,0,1),
(@GUID+11,18686,530,1,0,0,-2172.31,4091.34,3.00316,4.21182,28800,5,0,9144,13525,0,1),
(@GUID+12,18686,530,1,0,0,-3001.44,3297.82,0.537389,4.35947,28800,5,0,9144,13525,0,1),
(@GUID+13,18686,530,1,0,0,-3540.43,4051.46,66.3999,2.6905,28800,5,0,9144,13525,0,1),
-- Ever-Core the Punisher
(@GUID+14,18698,530,1,0,0,3014.36,4025.81,144.105,2.90805,28800,5,0,10466,5982,0,1),
(@GUID+15,18698,530,1,0,0,3835.65,3835.2,103.641,5.80224,28800,5,0,10466,5982,0,1),
(@GUID+16,18698,530,1,0,0,4824.65,2738.08,88.9073,0.75999,28800,5,0,10466,5982,0,1),
(@GUID+17,18698,530,1,0,0,4113.73,1677.64,130.749,0.237701,28800,5,0,10466,5982,0,1),
-- Fulgorge (should be 3 i think)
(@GUID+18,18678,530,1,0,0,-565.303,4343,49.9107,6.05994,28800,0,0,10682,0,0,0),
(@GUID+19,18678,530,1,0,0,-632.339,3908.47,28.9953,4.74599,28800,0,0,10682,0,0,0),
(@GUID+38,18678,530,1,0,0,-634.201,3795.52,28.99509,1.162743,28800,0,0,10682,0,0,0),
-- Goretooth
(@GUID+20,17144,530,1,0,0,-1762.6,8066.57,-104.023,1.86887,28800,0,0,11828,0,0,0),
(@GUID+21,17144,530,1,0,0,-1840.51,8450.93,-64.6652,4.69754,28800,0,0,11828,0,0,0),
(@GUID+22,17144,530,1,0,0,-1025.68,7114.78,2.37478,0.256121,28800,0,0,11828,0,0,0),
(@GUID+23,17144,530,1,0,0,-2876.55,6078.57,-4.24251,1.15226,28800,0,0,11828,0,0,0),
-- Hemathion
(@GUID+24,18692,530,1,0,0,2116.26,7250.19,365.147,2.86924,28800,0,0,13084,0,0,0),
(@GUID+25,18692,530,1,0,0,2699.59,7237.5,366.064,3.30389,28800,0,0,13084,0,0,0),
-- Mekthorg the Wild
(@GUID+26,18677,530,1,0,0,-575.456,3240.77,5.76784,4.69623,28800,0,0,10316,0,0,0),
(@GUID+27,18677,530,1,0,0,-1084.3,2014.46,67.6811,0.947525,28800,5,0,10316,0,0,1),
-- Speaker Mar'grom
(@GUID+28,18693,530,1,0,0,2365.59,6544.67,3.4638,1.66658,28800,0,0,10466,8973,0,0),
(@GUID+29,18693,530,1,0,0,1599.44,6433.12,-10.4082,0.215986,28800,0,0,10466,8973,0,0),
(@GUID+30,18693,530,1,0,0,1607.56,6423.05,-10.3477,0.577269,28800,5,0,10466,8973,0,1),
(@GUID+31,18693,530,1,0,0,2915.68,6000.98,-4.1535,4.87572,28800,5,0,10466,8973,0,1),
(@GUID+32,18693,530,1,0,0,3636.49,5349.23,-20.7,4.57491,28800,5,0,10466,8973,0,1),
-- Voidhunter Yar (1 spawn. circular pathing)
(@GUID+33,18683,530,1,0,0,-2422.61,8206.15,-38.3408,0.177212,28800,0,0,10466,11964,0,0),
-- Vorakem Doomspeaker
(@GUID+34,18679,530,1,0,0,175.918,1720.29,34.4088,3.26023,28800,0,0,8548,2568,0,0),
(@GUID+35,18679,530,1,0,0,-444.675,1851.37,78.3747,5.77743,28800,5,0,8548,2568,0,1),
(@GUID+36,18679,530,1,0,0,399.416,2204.89,118.365,0.918177,28800,5,0,8548,2568,0,1),
(@GUID+37,18679,530,1,0,0,362.142,3354.43,64.1364,1.86458,28800,5,0,8548,2568,0,1);

-- Defining Pooling_templates
DELETE FROM `pool_template` WHERE `entry` BETWEEN 1073 AND 1085;
INSERT INTO pool_template (`entry`,`max_limit`,`description`) VALUES
(1073,1, 'Okrek Rare Spawn (1 out 4)'),
(1074,1, 'Ambassador Jerrikar Rare Spawn (1 out 5)'),
(1075,1, 'Okrek Rare Spawn (1 out 3)'),
(1076,1, 'Crippler Rare Spawn (1 out 1)'),
(1077,1, 'Doomsayer Jurim Rare Spawn (1 out 5)'),
(1078,1, 'Ever-Core the Punisher Rare Spawn (1 out 4)'),
(1079,1, 'Fulgore Rare Spawn (1 out 3)'),
(1080,1, 'Goretooth Rare Spawn (1 out 4)'),
(1081,1, 'Hemathion Rare Spawn (1 out 2)'),
(1082,1, 'Mekthorg the Wild Rare Spawn (1 out 2)'),
(1083,1, 'Speaker Margrom Rare Spawn (1 out 5)'),
(1084,1, 'Voidhunter Yar Rare Spawn (1 out 1)'),
(1085,1, 'Vorakem Doomspeaker Rare Spawn (1 out 4)');

-- Pooling the Spawns
DELETE FROM `pool_creature` WHERE `pool_entry` BETWEEN 1073 AND 1085;
INSERT INTO pool_creature(`guid`,`pool_entry`,`chance`,`description`) VALUES
(85382,1073,25, 'Okrek - Spawnlocation 1'),
(85405,1073,25, 'Okrek - Spawnlocation 2'),
(85564,1073,25, 'Okrek - Spawnlocation 3'),
(85565,1073,25, 'Okrek - Spawnlocation 4'),
(@GUID,1074,20, 'Ambassador Jerrikar - Spawnlocation 1'),
(@GUID+1,1074,20, 'Ambassador Jerrikar - Spawnlocation 2'),
(@GUID+2,1074,20, 'Ambassador Jerrikar - Spawnlocation 3'),
(@GUID+3,1074,20, 'Ambassador Jerrikar - Spawnlocation 4'),
(@GUID+4,1074,20, 'Ambassador Jerrikar - Spawnlocation 5'),
(@GUID+5,1075,33, 'Chief Engineer Lorthander - Spawnlocation 1'),
(@GUID+6,1075,33, 'Chief Engineer Lorthander - Spawnlocation 2'),
(@GUID+7,1075,34, 'Chief Engineer Lorthander - Spawnlocation 3'),
(@GUID+8,1076,100, 'Crippler - Spawnlocation 1'),
(@GUID+9,1077,20, 'Doomsayer Jurim Spawnlocation 1'),
(@GUID+10,1077,20, 'Doomsayer Jurim Spawnlocation 2'),
(@GUID+11,1077,20, 'Doomsayer Jurim Spawnlocation 3'),
(@GUID+12,1077,20, 'Doomsayer Jurim Spawnlocation 4'),
(@GUID+13,1077,20, 'Doomsayer Jurim Spawnlocation 5'),
(@GUID+14,1078,25, 'Ever-Core the Punisher Spawnlocation 1'),
(@GUID+15,1078,25, 'Ever-Core the Punisher Spawnlocation 2'),
(@GUID+16,1078,25, 'Ever-Core the Punisher Spawnlocation 3'),
(@GUID+17,1078,25, 'Ever-Core the Punisher Spawnlocation 4'),
(@GUID+18,1079,33, 'Fulgore Spawnlocation 1'),
(@GUID+19,1079,33, 'Fulgore Spawnlocation 2'),
(@GUID+38,1079,33, 'Fulgore Spawnlocation 2'),
(@GUID+20,1080,25, 'Goretooth Spawnlocation 1'),
(@GUID+21,1080,25, 'Goretooth Spawnlocation 2'),
(@GUID+22,1080,25, 'Goretooth Spawnlocation 3'),
(@GUID+23,1080,25, 'Goretooth Spawnlocation 4'),
(@GUID+24,1081,50, 'Hemathion Spawnlocation 1'),
(@GUID+25,1081,50, 'Hemathion Spawnlocation 2'),
(@GUID+26,1082,50, 'Mekthorg the Wild Spawnlocation 1'),
(@GUID+27,1082,50, 'Mekthorg the Wild Spawnlocation 2'),
(@GUID+28,1083,20, 'Speaker Margrom Spawnlocation 1'),
(@GUID+29,1083,20, 'Speaker Margrom Spawnlocation 2'),
(@GUID+30,1083,20, 'Speaker Margrom Spawnlocation 3'),
(@GUID+31,1083,20, 'Speaker Margrom Spawnlocation 4'),
(@GUID+32,1083,20, 'Speaker Margrom Spawnlocation 5'),
(@GUID+33,1084,100, 'Voidhunter Yar Spawnlocation 1'),
(@GUID+34,1085,25, 'Vorakem Doomspeaker Spawnlocation 1'),
(@GUID+35,1085,25, 'Vorakem Doomspeaker Spawnlocation 2'),
(@GUID+36,1085,25, 'Vorakem Doomspeaker Spawnlocation 3'),
(@GUID+37,1085,25, 'Vorakem Doomspeaker Spawnlocation 4');