/*
 * This file is part of the OregonCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CharacterDatabase.h"

bool CharacterDatabaseConnection::Open(const std::string& infoString)
{
    if (!MySQLConnection::Open(infoString))
        return false;

    m_stmts.resize(MAX_CHARACTERDATABASE_STATEMENTS);
    /*
        ##################################
        LOAD YOUR PREPARED STATEMENTS HERE
        ##################################
    */
    PrepareStatement(CHAR_DEL_QUEST_POOL_SAVE, "DELETE FROM pool_quest_save WHERE pool_id = ?");
    PrepareStatement(CHAR_ADD_QUEST_POOL_SAVE, "INSERT INTO pool_quest_save (pool_id, quest_id) VALUES (?, ?)");

    return true;
}