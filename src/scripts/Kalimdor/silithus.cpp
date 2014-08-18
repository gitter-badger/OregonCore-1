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

/* ScriptData
SDName: Silithus
SD%Complete: 100
SDComment: Quest support: 7785, 8304, 8305, 8519.
SDCategory: Silithus
EndScriptData */

/* ContentData
npc_highlord_demitrian
npcs_rutgar_and_frankal
go_crystalline_tear
mob_qiraj_war_spawn
npc_anachronos_quest_trigger
npc_anachronos_the_ancient
EndContentData */

#include "ScriptPCH.h"

/*###
## npc_highlord_demitrian
###*/

#define GOSSIP_DEMITRIAN1 "What do you know of it?"
#define GOSSIP_DEMITRIAN2 "I am listening , Demitrian."
#define GOSSIP_DEMITRIAN3 "Continue, please."
#define GOSSIP_DEMITRIAN4 "A battle?"
#define GOSSIP_DEMITRIAN5 "<Nod>"
#define GOSSIP_DEMITRIAN6 "Caught unaware? How?"
#define GOSSIP_DEMITRIAN7 "So what did Ragnaros do next?"

bool GossipHello_npc_highlord_demitrian(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(7785) == QUEST_STATUS_NONE &&
        (pPlayer->HasItemCount(18563,1,false) || pPlayer->HasItemCount(18564,1,false)))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(6812, pCreature->GetGUID());
        return true;
}

bool GossipSelect_npc_highlord_demitrian(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(6842, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->SEND_GOSSIP_MENU(6843, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        pPlayer->SEND_GOSSIP_MENU(6844, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+3:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
        pPlayer->SEND_GOSSIP_MENU(6867, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+4:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
        pPlayer->SEND_GOSSIP_MENU(6868, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+5:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DEMITRIAN7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
        pPlayer->SEND_GOSSIP_MENU(6869, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+6:
        pPlayer->SEND_GOSSIP_MENU(6870, pCreature->GetGUID());

        ItemPosCountVec dest;
        uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 19016, 1);
        if (msg == EQUIP_ERR_OK)
            pPlayer->StoreNewItem(dest, 19016, true);
        break;
    }
    return true;
}

/*###
## npcs_rutgar_and_frankal
###*/

//gossip item text best guess
#define GOSSIP_ITEM1 "I seek information about Natalia"

#define GOSSIP_ITEM2 "That sounds dangerous!"
#define GOSSIP_ITEM3 "What did you do?"
#define GOSSIP_ITEM4 "Who?"
#define GOSSIP_ITEM5 "Women do that. What did she demand?"
#define GOSSIP_ITEM6 "What do you mean?"
#define GOSSIP_ITEM7 "What happened next?"

#define GOSSIP_ITEM11 "Yes, please continue"
#define GOSSIP_ITEM12 "What language?"
#define GOSSIP_ITEM13 "The Priestess attacked you?!"
#define GOSSIP_ITEM14 "I should ask the monkey about this"
#define GOSSIP_ITEM15 "Then what..."

//trigger creatures to kill
#define TRIGGER_RUTGAR 15222
#define TRIGGER_FRANKAL 15221

bool GossipHello_npcs_rutgar_and_frankal(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(8304) == QUEST_STATUS_INCOMPLETE &&
        pCreature->GetEntry() == 15170 &&
        !pPlayer->GetReqKillOrCastCurrentCount(8304, TRIGGER_RUTGAR))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    if (pPlayer->GetQuestStatus(8304) == QUEST_STATUS_INCOMPLETE &&
        pCreature->GetEntry() == 15171 &&
        pPlayer->GetReqKillOrCastCurrentCount(8304, TRIGGER_RUTGAR))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);

    pPlayer->SEND_GOSSIP_MENU(7754, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npcs_rutgar_and_frankal(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(7755, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(7756, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7757, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(7758, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(7759, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(7760, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:
            pPlayer->SEND_GOSSIP_MENU(7761, pCreature->GetGUID());
                                                            //'kill' our trigger to update quest status
            pPlayer->KilledMonsterCredit(TRIGGER_RUTGAR, 0);
            break;

        case GOSSIP_ACTION_INFO_DEF + 9:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(7762, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM12, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(7763, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM13, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(7764, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM14, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            pPlayer->SEND_GOSSIP_MENU(7765, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM15, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            pPlayer->SEND_GOSSIP_MENU(7766, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 14:
            pPlayer->SEND_GOSSIP_MENU(7767, pCreature->GetGUID());
                                                            //'kill' our trigger to update quest status
            pPlayer->KilledMonsterCredit(TRIGGER_FRANKAL, pCreature->GetGUID());
            break;
    }
    return true;
}

/*#####
# Quest: A Pawn on the Eternal Board
#####*/

/* ContentData
A Pawn on the Eternal Board - creatures, gameobjects and defines
mob_qiraj_war_spawn : Adds that are summoned in the Qiraj gates battle.
npc_anachronos_the_ancient : Creature that controls the event.
npc_anachronos_quest_trigger: controls the spawning of the BG War mobs.
go_crystalline_tear : GameObject that begins the event and hands out quest
TO DO: get correct spell IDs and timings for spells cast upon dragon transformations
TO DO: Dragons should use the HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF) after transformation,but for some unknown reason it doesnt work.
EndContentData */

enum eEternalBoard
{
    QUEST_A_PAWN_ON_THE_ETERNAL_BOARD = 8519,

    FACTION_HOSTILE       = 14,
    FACTION_FRIENDLY      = 35,

    C_ANACHRONOS          = 15381,
    C_FANDRAL_STAGHELM    = 15382,
    C_ARYGOS              = 15380,
    C_MERITHRA            = 15378,
    C_CAELESTRASZ         = 15379,

    ANACHRONOS_SAY_1      = -1000623,
    ANACHRONOS_SAY_2      = -1000624,
    ANACHRONOS_SAY_3      = -1000625,
    ANACHRONOS_SAY_4      = -1000626,
    ANACHRONOS_SAY_5      = -1000627,
    ANACHRONOS_SAY_6      = -1000628,
    ANACHRONOS_SAY_7      = -1000629,
    ANACHRONOS_SAY_8      = -1000630,
    ANACHRONOS_SAY_9      = -1000631,
    ANACHRONOS_SAY_10     = -1000632,
    ANACHRONOS_EMOTE_1    = -1000633,
    ANACHRONOS_EMOTE_2    = -1000634,
    ANACHRONOS_EMOTE_3    = -1000635,

    FANDRAL_SAY_1         = -1000636,
    FANDRAL_SAY_2         = -1000637,
    FANDRAL_SAY_3         = -1000638,
    FANDRAL_SAY_4         = -1000639,
    FANDRAL_SAY_5         = -1000640,
    FANDRAL_SAY_6         = -1000641,
    FANDRAL_EMOTE_1       = -1000642,
    FANDRAL_EMOTE_2       = -1000643,

    CAELESTRASZ_SAY_1     = -1000644,
    CAELESTRASZ_SAY_2     = -1000645,
    CAELESTRASZ_YELL_1    = -1000646,

    ARYGOS_SAY_1          = -1000647,
    ARYGOS_YELL_1         = -1000648,
    ARYGOS_EMOTE_1        = -1000649,

    MERITHRA_SAY_1        = -1000650,
    MERITHRA_SAY_2        = -1000651,
    MERITHRA_YELL_1       = -1000652,
    MERITHRA_EMOTE_1      = -1000653,

    GO_GATE_OF_AHN_QIRAJ  = 176146,
    GO_GLYPH_OF_AHN_QIRAJ = 176148,
    GO_ROOTS_OF_AHN_QIRAJ = 176147,

    LONG_FORGOTTEN_MEMORIES             = 8305,
    EVENT_AREA_RADIUS                   = 65,
    EVENT_COOLDOWN                      = 500000 //in ms. appear after event completed or failed (should be = Adds despawn time)

};

struct QuestCinematic
{
    int32 TextId;
    uint32 Creature, Timer;
};

// Creature 0 - Anachronos, 1 - Fandral, 2 - Arygos, 3 - Merithra, 4 - Caelestrasz
static QuestCinematic EventAnim[]=
{
    {ANACHRONOS_SAY_1, 0, 2000},
    {FANDRAL_SAY_1, 1, 4000},
    {MERITHRA_EMOTE_1, 3, 500},
    {MERITHRA_SAY_1, 3, 500},
    {ARYGOS_EMOTE_1, 2, 2000},
    {CAELESTRASZ_SAY_1, 4, 8000},
    {MERITHRA_SAY_2, 3, 6000},
    {0,3,2000},
    {MERITHRA_YELL_1, 3, 2500},
    {0, 3, 3000},//Morph
    {0,3,4000},//EmoteLiftoff
    {0, 3, 4000},// spell
    {0, 3, 1250},//fly
    {0, 3, 250},//remove flags
    {ARYGOS_SAY_1, 2, 3000},
    {0,3,2000},
    {ARYGOS_YELL_1, 2, 3000},
    {0, 3, 3000},//Morph
    {0,3,4000},//EmoteLiftoff
    {0, 3, 4000},// spell
    {0, 3, 1000},//fly
    {0, 3, 1000},//remove flags
    {CAELESTRASZ_SAY_2, 4, 5000},
    {0,3,3000},
    {CAELESTRASZ_YELL_1, 4, 3000},
    {0, 3, 3000},//Morph
    {0,3,4000},//EmoteLiftoff
    {0, 3, 2500},// spell
    {ANACHRONOS_SAY_2, 0, 2000},
    {0, 3, 250},//fly
    {0, 3, 25},//remove flags
    {FANDRAL_SAY_2, 1, 3000},
    {ANACHRONOS_SAY_3, 0, 10000},//Both run through the armies
    {0,3,2000},// Sands will stop
    {0,3,8000},// Summon Gate
    {ANACHRONOS_SAY_4, 0, 4000},
    {0, 0, 2000},//spell 1-> Arcane cosmetic (Mobs freeze)
    {0, 0, 5000}, //Spell 2-> Arcane long cosmetic (barrier appears) (Barrier -> Glyphs)
    {0, 0, 7000},//BarrieR
    {0, 0, 4000},//Glyphs
    {ANACHRONOS_SAY_5, 0, 2000},
    {0, 0, 4000},// Roots
    {FANDRAL_SAY_3, 1, 3000},//Root Text
    {FANDRAL_EMOTE_1, 1, 3000},//falls knee
    {ANACHRONOS_SAY_6, 0, 3000},
    {ANACHRONOS_SAY_7, 0, 3000},
    {ANACHRONOS_SAY_8, 0, 8000},
    {ANACHRONOS_EMOTE_1, 0, 1000},//Give Scepter
    {FANDRAL_SAY_4, 1, 3000},
    {FANDRAL_SAY_5, 1, 3000},//->Equip hammer~Scepter, throw it at door
    {FANDRAL_EMOTE_2, 1, 3000},//Throw hammer at door.
    {ANACHRONOS_SAY_9, 0, 3000},
    {FANDRAL_SAY_6, 1, 3000},//fandral goes away
    {ANACHRONOS_EMOTE_2, 0, 3000},
    {ANACHRONOS_EMOTE_3, 0, 3000},
    {0, 0, 2000},
    {0, 0, 2000},
    {0, 0, 4000},
    {ANACHRONOS_SAY_10, 0, 3000},
    {0, 0, 2000},
    {0, 0, 3000},
    {0, 0, 15000},
    {0, 0, 5000},
    {0, 0, 3500},
    {0, 0, 5000},
    {0, 0, 3500},
    {0, 0, 5000},
    {0, 0, 0}
};

struct Location
{
    float x, y, z, o;
};

//Cordinates for Spawns
static Location SpawnLocation[]=
{
    //Kaldorei Infantry
    {-8085, 1528, 2.61f, 3.141592f},
    {-8080, 1526, 2.61f, 3.141592f},
    {-8085, 1524, 2.61f, 3.141592f},
    {-8080, 1522, 2.61f, 3.141592f},
    {-8085, 1520, 2.61f, 3.141592f},

    {-8085, 1524, 2.61f, 3.141592f},
    {-8080, 1522, 2.61f, 3.141592f},
    {-8085, 1520, 2.61f, 3.141592f},
    {-8080, 1518, 2.61f, 3.141592f},
    {-8085, 1516, 2.61f, 3.141592f},

    {-8085, 1518, 2.61f, 3.141592f},
    {-8080, 1516, 2.61f, 3.141592f},
    {-8080, 1520, 2.61f, 3.141592f},
    {-8080, 1424, 2.61f, 3.141592f},
    {-8085, 1422, 2.61f, 3.141592f},
    // 2 waves of warriors
    {-8082, 1528, 2.61f, 3.141592f},
    {-8078, 1525, 2.61f, 3.141592f},
    {-8082, 1524, 2.61f, 3.141592f},
    {-8078, 1526, 2.61f, 3.141592f},
    {-8082, 1527, 2.61f, 3.141592f},

    {-8082, 1524, 2.61f, 3.141592f},
    {-8078, 1522, 2.61f, 3.141592f},
    {-8082, 1520, 2.61f, 3.141592f},
    {-8078, 1518, 2.61f, 3.141592f},
    {-8082, 1516, 2.61f, 3.141592f},

    {-8082, 1523, 2.61f, 3.141592f},
    {-8078, 1521, 2.61f, 3.141592f},
    {-8082, 1528, 2.61f, 3.141592f},
    {-8078, 1519, 2.61f, 3.141592f},
    {-8082, 1526, 2.61f, 3.141592f},

    {-8082, 1524, 2.61f, 3.141592f},
    {-8078, 1522, 2.61f, 3.141592f},
    {-8082, 1520, 2.61f, 3.141592f},
    {-8078, 1518, 2.61f, 3.141592f},
    {-8082, 1516, 2.61f, 3.141592f},

    //Anubisath Conqueror
    {-8088, 1510, 2.61f, 0},
    {-8084, 1520, 2.61f, 0},
    {-8088, 1530, 2.61f, 0},

    //Qiraj Wasp
    {-8080, 1513, 2.61f, 0},
    {-8082, 1523, 2.61f, 0},
    {-8085, 1518, 2.61f, 0},
    {-8082, 1516, 2.61f, 0},
    {-8085, 1520, 2.61f, 0},
    {-8080, 1528, 2.61f, 0},

    {-8082, 1513, 2.61f, 0},
    {-8079, 1523, 2.61f, 0},
    {-8080, 1531, 2.61f, 0},
    {-8079, 1516, 2.61f, 0},
    {-8082, 1520, 2.61f, 0},
    {-8080, 1518, 2.61f, 0},

    //Qiraj Tank
    {-8081, 1514, 2.61f, 0},
    {-8081, 1520, 2.61f, 0},
    {-8081, 1526, 2.61f, 0},
    {-8081, 1512, 2.61f, 0},
    {-8082, 1520, 2.61f, 0},
    {-8081, 1528, 2.61f, 0},

    //Anubisath Conqueror
    {-8082, 1513, 2.61f, 3.141592f},
    {-8082, 1520, 2.61f, 3.141592f},
    {-8082, 1527, 2.61f, 3.141592f},
};

struct WaveData
{
    uint8 SpawnCount, UsedSpawnPoint;
    uint32 CreatureId, SpawnTimer, YellTimer, DespTimer;
    int32 WaveTextId;
};

static WaveData WavesInfo[] =
{
    {30, 0, 15423, 0, 0,24000, 0},   //Kaldorei Soldier
    {3, 35, 15424, 0, 0,24000, 0},   //Anubisath Conqueror
    {12, 38, 15414, 0, 0,24000, 0},  //Qiraji Wasps
    {6, 50, 15422, 0, 0,24000, 0},   //Qiraji Tanks
    {15, 15, 15423, 0, 0,24000, 0}   //Kaldorei Soldier

};

struct SpawnSpells
{
    uint32 Timer1, Timer2, SpellId;
};

static SpawnSpells SpawnCast[]=//
{
    {100000, 2000, 33652},   // Stop Time
    {38500, 300000, 28528},  // Poison Cloud
    {58000, 300000, 35871},  // Frost Debuff (need correct spell)
    {80950, 300000, 42075},  // Fire Explosion (need correct spell however this one looks cool)
};
/*#####
# npc_anachronos_the_ancient
######*/

struct npc_anachronos_the_ancientAI : public ScriptedAI
{
    npc_anachronos_the_ancientAI(Creature* c) : ScriptedAI(c) {}

    uint32 AnimationTimer;
    uint8 AnimationCount;

    uint64 AnachronosQuestTriggerGUID;
    uint64 MerithraGUID;
    uint64 ArygosGUID;
    uint64 CaelestraszGUID;
    uint64 FandralGUID;
    uint64 PlayerGUID;
    bool eventEnd;

    void Reset()
    {
        AnimationTimer = 1500;
        AnimationCount = 0;
        AnachronosQuestTriggerGUID = 0;
        MerithraGUID = 0;
        ArygosGUID = 0;
        CaelestraszGUID = 0;
        FandralGUID = 0;
        PlayerGUID = 0;
        eventEnd = false;

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void HandleAnimation()
    {
        Player* plr = Unit::GetPlayer(*me, PlayerGUID);
        if (!plr)
            return;

        Unit* Fandral = plr->FindNearestCreature(C_FANDRAL_STAGHELM, 100, me);
        Unit* Arygos = plr->FindNearestCreature(C_ARYGOS, 100,me);
        Unit* Caelestrasz = plr->FindNearestCreature(C_CAELESTRASZ, 100, me);
        Unit* Merithra = plr->FindNearestCreature(C_MERITHRA, 100,me);

        if (!Fandral || !Arygos || !Caelestrasz || !Merithra)
            return;

        Unit* mob;
        AnimationTimer = EventAnim[AnimationCount].Timer;
        if (eventEnd == false)
        {
            switch(AnimationCount)
            {
                case 0:
                    DoScriptText(ANACHRONOS_SAY_1, me , Fandral);
                    break;
                case 1:
                    Fandral->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    DoScriptText(FANDRAL_SAY_1, Fandral,me);
                    break;
                case 2:
                    Fandral->SetUInt64Value(UNIT_FIELD_TARGET,0);
                    DoScriptText(MERITHRA_EMOTE_1,Merithra);
                    break;
                case 3:
                    DoScriptText(MERITHRA_SAY_1,Merithra);
                    break;
                case 4:
                    DoScriptText(ARYGOS_EMOTE_1,Arygos);
                    break;
                case 5:
                    Caelestrasz->SetUInt64Value(UNIT_FIELD_TARGET, Fandral->GetGUID());
                    DoScriptText(CAELESTRASZ_SAY_1, Caelestrasz);
                    break;
                case 6:
                    DoScriptText(MERITHRA_SAY_2, Merithra);
                    break;
                case 7:
                    Caelestrasz->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                    Merithra->GetMotionMaster()->MoveCharge(-8065,1530,2.61f,10);
                    break;
                case 8:
                    DoScriptText(MERITHRA_YELL_1,Merithra);
                    break;
                case 9:
                    Merithra->CastSpell(Merithra,25105,true);
                    break;
                case 10:
                    Merithra->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                    Merithra->AddUnitMovementFlag(MOVEFLAG_LEVITATING);
                    Merithra->GetMotionMaster()->MoveCharge(-8065,1530,6.61f,3);
                    break;
                case 11:
                    Merithra->CastSpell(Merithra,24818,false);
                    break;
                case 12:
                    Merithra->GetMotionMaster()->MoveCharge(-8100,1530,50,42);
                    break;
                case 13:
                    break;
                case 14:
                    DoScriptText(ARYGOS_SAY_1,Arygos);
                    Merithra->SetVisibility(VISIBILITY_OFF);
                    break;
                case 15:
                    Arygos->GetMotionMaster()->MoveCharge(-8065,1530,2.61f,10);
                    Merithra->GetMotionMaster()->MoveCharge(-8034.535f,1535.14f,2.61f,42);
                    break;
                case 16:
                    DoScriptText(ARYGOS_YELL_1, Arygos);
                    break;
                case 17:
                    Arygos->CastSpell(Arygos,25107,true);
                    break;
                case 18:
                    Arygos->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                    Arygos->AddUnitMovementFlag(MOVEFLAG_LEVITATING);
                    Arygos->GetMotionMaster()->MoveCharge(-8065,1530,6.61f,42);
                    break;
                case 19:
                    Arygos->CastSpell(Arygos,44799,false);
                    break;
                case 20:
                    Arygos->GetMotionMaster()->MoveCharge(-8095,1530,50,42);
                    break;
                case 21:
                    break;
                case 22:
                    DoScriptText(CAELESTRASZ_SAY_2,Caelestrasz, Fandral);
                    break;
                case 23:
                    Caelestrasz->GetMotionMaster()->MoveCharge(-8065,1530,2.61f,10);
                    Arygos->SetVisibility(VISIBILITY_OFF);
                    Arygos->GetMotionMaster()->MoveCharge(-8034.535f,1535.14f,2.61f,10);
                    break;
                case 24:
                    DoScriptText(CAELESTRASZ_YELL_1, Caelestrasz);
                    break;
                case 25:
                    Caelestrasz->CastSpell(Caelestrasz,25106,true);
                    break;
                case 26:
                    Caelestrasz->HandleEmoteCommand(254);
                    Caelestrasz->AddUnitMovementFlag(MOVEFLAG_LEVITATING);
                    Caelestrasz->GetMotionMaster()->MoveCharge(-8065,1530,7.61f,4);
                    break;
                case 27:
                    Caelestrasz->CastSpell(Caelestrasz,43294,false);
                    break;
                case 28:
                    DoScriptText(ANACHRONOS_SAY_2,me, Fandral);
                    break;
                case 29:
                    Caelestrasz->GetMotionMaster()->MoveCharge(-8095,1530,50,42);
                    DoScriptText(FANDRAL_SAY_2, Fandral, me);
                    break;
                case 30:
                    break;
                case 31:
                    DoScriptText(ANACHRONOS_SAY_3, me, Fandral);
                    break;
                case 32:
                    Caelestrasz->SetVisibility(VISIBILITY_OFF);
                    Caelestrasz->GetMotionMaster()->MoveCharge(-8034.535f,1535.14f,2.61f,42);
                    Fandral->GetMotionMaster()->MoveCharge(-8108,1529,2.77f,8);
                    me->GetMotionMaster()->MoveCharge(-8113,1525,2.77f,8);
                    break;//both run to the gate
                case 33:
                    DoScriptText(ANACHRONOS_SAY_4, me);
                    Caelestrasz->GetMotionMaster()->MoveCharge(-8050,1473,65,15);
                    break; //Text: sands will stop
                case 34:
                    DoCast(plr, 23017, true);//Arcane Channeling
                    break;
                case 35:
                    me->CastSpell(-8088,1520.43f,2.67f,25158,true);
                    break;
                case 36:
                    DoCast(plr, 25159, true);
                    break;
                case 37:
                    me->SummonGameObject(GO_GATE_OF_AHN_QIRAJ,-8130,1525,17.5f,0,0,0,0,0,0);
                    break;
                case 38:
                    DoCast(plr, 25166, true);
                    me->SummonGameObject(GO_GLYPH_OF_AHN_QIRAJ,-8130,1525,17.5f,0,0,0,0,0,0);
                    break;
                case 39:
                    DoScriptText(ANACHRONOS_SAY_5, me, Fandral);
                    break;
                case 40:
                    Fandral->CastSpell(me, 25167, true);
                    break;
                case 41:
                    Fandral->SummonGameObject(GO_ROOTS_OF_AHN_QIRAJ,-8130,1525,17.5f,0,0,0,0,0,0);
                    DoScriptText(FANDRAL_SAY_3, Fandral);
                    break;
                case 42:
                    me->CastStop();
                    DoScriptText(FANDRAL_EMOTE_1, Fandral);
                    break;
                case 43:
                    Fandral->CastStop();
                    break;
                case 44:
                    DoScriptText(ANACHRONOS_SAY_6, me);
                    break;
                case 45:
                    DoScriptText(ANACHRONOS_SAY_7, me);
                    break;
                case 46:
                    DoScriptText(ANACHRONOS_SAY_8, me);
                    me->GetMotionMaster()->MoveCharge(-8110,1527,2.77f,4);
                    break;
                case 47:
                    DoScriptText(ANACHRONOS_EMOTE_1, me);
                    break;
                case 48:
                    DoScriptText(FANDRAL_SAY_4,Fandral,me);
                    break;
                case 49:
                    DoScriptText(FANDRAL_SAY_5,Fandral,me);
                    break;
                case 50:
                    DoScriptText(FANDRAL_EMOTE_2,Fandral);
                    Fandral->CastSpell(-8127,1525,17.5f,33806,true);
                    break;
                case 51:
                {
                    uint32 loopbreaker = 0;
                    uint32 entries[4] = { 15423, 15424, 15414, 15422 };
                    for (uint8 i = 0; i < 4; i++)
                    {
                        mob = plr->FindNearestCreature(entries[i],300,true);
                        loopbreaker = 0;
                        while (mob != NULL && loopbreaker < 67)
                        {
                            mob->RemoveFromWorld();
                            mob = plr->FindNearestCreature(entries[i],300,true);
                            loopbreaker++;
                        }
                        mob = plr->FindNearestCreature(entries[i],300,false);
                        loopbreaker = 0;
                        while (mob != NULL && loopbreaker < 67)
                        {
                            mob->RemoveFromWorld();
                            mob = plr->FindNearestCreature(entries[i],300,false);
                            loopbreaker++;
                        }
                    }
                    break;
                }
                case 52:
                    Fandral->GetMotionMaster()->MoveCharge(-8028.75f, 1538.795f, 2.61f,4);
                    DoScriptText(ANACHRONOS_SAY_9, me,Fandral);
                    break;
                case 53:
                    DoScriptText(FANDRAL_SAY_6,Fandral);
                    break;
                case 54:
                    DoScriptText(ANACHRONOS_EMOTE_2,me);
                    break;
                case 55:
                    Fandral->SetVisibility(VISIBILITY_OFF);
                    break;
                case 56:
                    DoScriptText(ANACHRONOS_EMOTE_3, me);
                    me->GetMotionMaster()->MoveCharge(-8116,1522,3.65f,4);
                    break;
                case 57:
                    me->GetMotionMaster()->MoveCharge(-8116.7f,1527,3.7f,4);
                    break;
                case 58:
                    me->GetMotionMaster()->MoveCharge(-8112.67f,1529.9f,2.86f,4);
                    break;
                case 59:
                    me->GetMotionMaster()->MoveCharge(-8117.99f,1532.24f,3.94f,4);
                    break;
                case 60:
                    if (plr)
                        DoScriptText(ANACHRONOS_SAY_10, me,plr);
                    me->GetMotionMaster()->MoveCharge(-8113.46f,1524.16f,2.89f,4);
                    break;
                case 61:
                    me->GetMotionMaster()->MoveCharge(-8057.1f,1470.32f,2.61f,6);
                    if (plr->IsInRange(me,0,15))
                        plr->GroupEventHappens(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD ,me);
                    break;
                case 62:
                    me->SetDisplayId(15500);
                    break;
                case 63:
                    me->HandleEmoteCommand(254);
                    me->AddUnitMovementFlag(MOVEFLAG_LEVITATING);
                    break;
                case 64:
                    me->GetMotionMaster()->MoveCharge(-8000,1400,150,9);
                    break;
                case 65:
                    me->SetVisibility(VISIBILITY_OFF);
                    if (Creature* AnachronosQuestTrigger = (Unit::GetCreature(*me, AnachronosQuestTriggerGUID)))
                    {
                        DoScriptText(ARYGOS_YELL_1,me);
                        AnachronosQuestTrigger->AI()->EnterEvadeMode();
                        eventEnd=true;
                    }
                    break;
            }
        }
        ++AnimationCount;
    }

    void UpdateAI(const uint32 diff)
    {
        if (AnimationTimer)
        {
            if (AnimationTimer <= diff)
                HandleAnimation();
            else AnimationTimer -= diff;
        }
        if (AnimationCount < 65)
            me->CombatStop();
        if (AnimationCount == 65 || eventEnd)
            me->AI()->EnterEvadeMode();
    }
};

/*######
# mob_qiraj_war_spawn
######*/

struct mob_qiraj_war_spawnAI : public ScriptedAI
{
    mob_qiraj_war_spawnAI(Creature* c) : ScriptedAI(c) {}

    uint64 MobGUID;
    uint64 PlayerGUID;
    uint32 SpellTimer1, SpellTimer2, SpellTimer3,SpellTimer4;
    bool Timers;
    bool hasTarget;

    void Reset()
    {
        MobGUID = 0;
        PlayerGUID = 0;
        Timers = false;
        hasTarget = false;
    }

    void EnterCombat(Unit* /*who*/) {}
    void JustDied(Unit* /*slayer*/);

    void UpdateAI(const uint32 diff)
    {
        Unit *pTarget = NULL;
        //Player* plr = me->GetPlayer(PlayerGUID);

        if (!Timers)
        {
            if (me->GetEntry() == 15424 || me->GetEntry() == 15422 || me->GetEntry() == 15414) //all but Kaldorei Soldiers
            {
                SpellTimer1 = SpawnCast[1].Timer1;
                SpellTimer2 = SpawnCast[2].Timer1;
                SpellTimer3 = SpawnCast[3].Timer1;
            }
            if (me->GetEntry() == 15423 || me->GetEntry() == 15424 || me->GetEntry() == 15422 || me->GetEntry() == 15414)
                SpellTimer4 = SpawnCast[0].Timer1;
            Timers = true;
        }
        if (me->GetEntry() == 15424 || me->GetEntry() == 15422|| me->GetEntry() == 15414)
        {
            if (SpellTimer1 <= diff)
            {
                DoCast(me, SpawnCast[1].SpellId);
                DoCast(me, 24319);
                SpellTimer1 = SpawnCast[1].Timer2;
            } else SpellTimer1 -= diff;
            if (SpellTimer2 <= diff)
            {
                DoCast(me, SpawnCast[2].SpellId);
                SpellTimer2 = SpawnCast[2].Timer2;
            } else SpellTimer2 -= diff;
            if (SpellTimer3 <= diff)
            {
                DoCast(me, SpawnCast[3].SpellId);
                SpellTimer3 = SpawnCast[3].Timer2;
            } else SpellTimer3 -= diff;
        }
        if (me->GetEntry() == 15423 || me->GetEntry() == 15424 || me->GetEntry() == 15422 || me->GetEntry() == 15414)
        {
            if (SpellTimer4 <= diff)
            {
                me->RemoveAllAttackers();
                me->AttackStop();
                DoCast(me, 15533);
                SpellTimer4 = SpawnCast[0].Timer2;
            } else SpellTimer4 -= diff;
        }
        if (!hasTarget)
        {
            if (me->GetEntry() == 15424 || me->GetEntry() == 15422 || me->GetEntry() == 15414)
                pTarget = me->FindNearestCreature(15423,20,true);
            if (me->GetEntry() == 15423)
            {
                uint8 tar = urand(0,2);

                if (tar == 0)
                    pTarget = me->FindNearestCreature(15422,20,true);
                else if (tar == 1)
                    pTarget = me->FindNearestCreature(15424,20,true);
                else if (tar == 2)
                    pTarget = me->FindNearestCreature(15414,20,true);
            }
            hasTarget = true;
            if (pTarget)
                me->AI()->AttackStart(pTarget);
        }
        if (!(me->FindNearestCreature(15379,60)))
            DoCast(me, 33652);

        if (!UpdateVictim())
        {
            hasTarget = false;
            return;
        }

        DoMeleeAttackIfReady();
    }
};

/*#####
# npc_anachronos_quest_trigger
#####*/

struct npc_anachronos_quest_triggerAI : public ScriptedAI
{
    npc_anachronos_quest_triggerAI(Creature* c) : ScriptedAI(c) {}

    uint64 PlayerGUID;

    uint32 WaveTimer;
    uint32 AnnounceTimer;

    int8 LiveCount;
    uint8 WaveCount;

    bool EventStarted;
    bool Announced;
    bool Failed;

    void Reset()
    {
        PlayerGUID = 0;

        WaveTimer = 2000;
        AnnounceTimer = 1000;
        LiveCount = 0;
        WaveCount = 0;

        EventStarted = false;
        Announced = false;
        Failed = false;

        me->SetVisibility(VISIBILITY_OFF);
    }

    void SummonNextWave()
    {
        //uint8 count = WavesInfo[WaveCount].SpawnCount;
        uint8 locIndex = WavesInfo[WaveCount].UsedSpawnPoint;
        //uint8 KaldoreiSoldierCount = 0;
        //uint8 AnubisathConquerorCount = 0;
        //uint8 QirajiWaspCount = 0;
        for (uint8 i = 0; i < (sizeof(SpawnLocation)/sizeof(*SpawnLocation)); ++i)
        {
            Creature* Spawn = NULL;
            float X = SpawnLocation[locIndex + i].x;
            float Y = SpawnLocation[locIndex + i].y;
            float Z = SpawnLocation[locIndex + i].z;
            float O = SpawnLocation[locIndex + i].o;
            uint32 desptimer = WavesInfo[WaveCount].DespTimer;
            Spawn = me->SummonCreature(WavesInfo[WaveCount].CreatureId, X, Y, Z, O, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, desptimer);

            if (Spawn)
            {
                Spawn->LoadCreaturesAddon();
                if (Spawn->GetGUID() == 15423)
                    Spawn->SetDisplayId(15427+rand()%4);
                if (i >= 30) WaveCount = 1;
                if (i >= 33) WaveCount = 2;
                if (i >= 45) WaveCount = 3;
                if (i >= 51) WaveCount = 4;

                if (WaveCount < 5) //1-4 Wave
                {
                    CAST_AI(mob_qiraj_war_spawnAI, Spawn->AI())->MobGUID = me->GetGUID();
                    CAST_AI(mob_qiraj_war_spawnAI, Spawn->AI())->PlayerGUID = PlayerGUID;
                }
            }
        }
        WaveTimer = WavesInfo[WaveCount].SpawnTimer;
        AnnounceTimer = WavesInfo[WaveCount].YellTimer;
    }

    void CheckEventFail()
    {
        Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);

        if (!pPlayer)
            return;

        if (Group *EventGroup = pPlayer->GetGroup())
        {
            Player* GroupMember;

            uint8 GroupMemberCount = 0;
            uint8 DeadMemberCount = 0;
            uint8 FailedMemberCount = 0;

            const Group::MemberSlotList members = EventGroup->GetMemberSlots();

            for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
            {
                GroupMember = (Unit::GetPlayer(*me, itr->guid));

                if (!GroupMember)
                    continue;

                if (!GroupMember->IsWithinDistInMap(me, EVENT_AREA_RADIUS) && GroupMember->GetQuestStatus(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD) == QUEST_STATUS_INCOMPLETE)
                {
                     GroupMember->FailQuest(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD);
                     GroupMember->SetQuestStatus(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD, QUEST_STATUS_NONE);
                     ++FailedMemberCount;
                }
                ++GroupMemberCount;

                if (GroupMember->isDead())
                    ++DeadMemberCount;
            }

            if (GroupMemberCount == FailedMemberCount || !pPlayer->IsWithinDistInMap(me, EVENT_AREA_RADIUS))
                Failed = true; //only so event can restart
        }
    }
    void LiveCounter()
    {
        --LiveCount;
        if (!LiveCount)
            Announced = false;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!PlayerGUID || !EventStarted)
            return;

        if (WaveCount < 4)
        {
            if (!Announced && AnnounceTimer <= diff)
            {
                DoScriptText(WavesInfo[WaveCount].WaveTextId, me);
                Announced = true;
            } else AnnounceTimer -= diff;

            if (WaveTimer <= diff)
                SummonNextWave();
            else WaveTimer -= diff;
        }
        CheckEventFail();
        if (WaveCount == 4 || Failed)
            EnterEvadeMode();
    };
};

void mob_qiraj_war_spawnAI::JustDied(Unit* /*slayer*/)
{
    me->RemoveCorpse();
    if (Creature* Mob = (Unit::GetCreature(*me, MobGUID)))
        CAST_AI(npc_anachronos_quest_triggerAI, Mob->AI())->LiveCounter();

};

/*#####
# go_crystalline_tear
######*/

       bool Hello_go_crystalline_tear(Player* pPlayer, GameObject* pGO)
       {
           if (pGO->GetGoType() == 2)
           {
               pPlayer->PrepareQuestMenu(pGO->GetGUID());
               pPlayer->SendPreparedQuest(pGO->GetGUID());
           }

           if (pPlayer->GetQuestStatus(LONG_FORGOTTEN_MEMORIES) != QUEST_STATUS_COMPLETE)
               pPlayer->AreaExploredOrEventHappens(LONG_FORGOTTEN_MEMORIES);
           return true;
       }

bool OnQuestAccept(Player* plr, GameObject* go, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_A_PAWN_ON_THE_ETERNAL_BOARD)
    {

        if (Unit* Anachronos_Quest_Trigger = go->FindNearestCreature(15454, 100, plr))
        {

            Unit *Merithra = Anachronos_Quest_Trigger->SummonCreature(15378,-8034.535f,1535.14f,2.61f,0,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,220000);
            Unit *Caelestrasz = Anachronos_Quest_Trigger->SummonCreature(15379,-8032.767f, 1533.148f,2.61f, 1.5f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,220000);
            Unit *Arygos = Anachronos_Quest_Trigger->SummonCreature(15380,-8034.52f, 1537.843f, 2.61f, 5.7f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,220000);
            /* Unit *Fandral = */ Anachronos_Quest_Trigger->SummonCreature(15382,-8028.462f, 1535.843f, 2.61f, 3.141592f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,220000);
            Creature *Anachronos = Anachronos_Quest_Trigger->SummonCreature(15381,-8028.75f, 1538.795f, 2.61f, 4,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,220000);

            if (Merithra)
            {
                Merithra->SetUInt32Value(UNIT_NPC_FLAGS, 0);
                Merithra->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
                Merithra->SetDisplayId(15420);
                Merithra->setFaction(35);
            }

            if (Caelestrasz)
            {
                Caelestrasz->SetUInt32Value(UNIT_NPC_FLAGS, 0);
                Caelestrasz->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
                Caelestrasz->SetDisplayId(15419);
                Caelestrasz->setFaction(35);
            }

            if (Arygos)
            {
                Arygos->SetUInt32Value(UNIT_NPC_FLAGS, 0);
                Arygos->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
                Arygos->SetDisplayId(15418);
                Arygos->setFaction(35);
            }

            if (Anachronos)
            {
                CAST_AI(/*npc_anachronos_the_ancient::*/npc_anachronos_the_ancientAI, Anachronos->AI())->PlayerGUID = plr->GetGUID();
                CAST_AI(/*npc_anachronos_quest_trigger::*/npc_anachronos_quest_triggerAI, CAST_CRE(Anachronos_Quest_Trigger)->AI())->Failed=false;
                CAST_AI(/*npc_anachronos_quest_trigger::*/npc_anachronos_quest_triggerAI, CAST_CRE(Anachronos_Quest_Trigger)->AI())->PlayerGUID = plr->GetGUID();
                CAST_AI(/*npc_anachronos_quest_trigger::*/npc_anachronos_quest_triggerAI, CAST_CRE(Anachronos_Quest_Trigger)->AI())->EventStarted=true;
                CAST_AI(/*npc_anachronos_quest_trigger::*/npc_anachronos_quest_triggerAI, CAST_CRE(Anachronos_Quest_Trigger)->AI())->Announced=true;
            }
        }
    }
    return true;
}


CreatureAI* Getmob_qiraj_war_spawnAI(Creature* pCreature)
{
    return new mob_qiraj_war_spawnAI (pCreature);
}

CreatureAI* Getnpc_anachronos_quest_triggerAI(Creature* pCreature)
{
    return new npc_anachronos_quest_triggerAI (pCreature);
}

CreatureAI* Getnpc_anachronos_the_ancientAI(Creature* pCreature)
{
    return new npc_anachronos_the_ancientAI (pCreature);
}

void AddSC_silithus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_highlord_demitrian";
    newscript->pGossipHello =  &GossipHello_npc_highlord_demitrian;
    newscript->pGossipSelect = &GossipSelect_npc_highlord_demitrian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npcs_rutgar_and_frankal";
    newscript->pGossipHello =   &GossipHello_npcs_rutgar_and_frankal;
    newscript->pGossipSelect =  &GossipSelect_npcs_rutgar_and_frankal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_crystalline_tear";
    newscript->pGOHello = &Hello_go_crystalline_tear;
    newscript->pGOQuestAccept = &OnQuestAccept;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_qiraj_war_spawn";
    newscript->GetAI = Getmob_qiraj_war_spawnAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_anachronos_quest_trigger";
    newscript->GetAI = Getnpc_anachronos_quest_triggerAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_anachronos_the_ancient";
    newscript->GetAI = Getnpc_anachronos_the_ancientAI;
    newscript->RegisterSelf();
}

