/* GnollHack File Change Notice: This file has been changed from the original. Date of last change: 2022-08-14 */

/* GnollHack 4.0    quest.h    $NHDT-Date: 1432512779 2015/05/25 00:12:59 $  $NHDT-Branch: master $:$NHDT-Revision: 1.10 $ */
/* Copyright (c) Mike Stephenson 1991.                  */
/* GnollHack may be freely redistributed.  See license for details. */

#ifndef QUEST_H
#define QUEST_H

struct q_score {              /* Quest "scorecard" */
    Bitfield(first_start, 1); /* only set the first time */
    Bitfield(met_leader, 1);  /* has met the leader */
    Bitfield(not_ready, 3);   /* rejected due to alignment, etc. */
    Bitfield(pissed_off, 1);  /* got the leader angry */
    Bitfield(got_quest, 1);   /* got the quest assignment */

    Bitfield(first_locate, 1); /* only set the first time */
    Bitfield(met_intermed, 1); /* used if the locate is a person. */
    Bitfield(got_final, 1);    /* got the final quest assignment */

    Bitfield(made_goal, 3);      /* # of times on goal level */
    Bitfield(met_nemesis, 1);    /* has met the nemesis before */
    Bitfield(killed_nemesis, 1); /* set when the nemesis is killed */
    Bitfield(in_battle, 1);      /* set when nemesis fighting you */

    Bitfield(cheater, 1);          /* set if cheating detected */
    Bitfield(touched_artifact, 1); /* for a special message */
    Bitfield(offered_artifact, 1); /* offered to leader */
    Bitfield(got_thanks, 1);       /* final message from leader */

    /* used by questpgr code when messages want to use pronouns
       (set up at game start instead of waiting until monster creation;
       1 bit each would suffice--nobody involved is actually neuter) */
    Bitfield(ldrgend, 2); /* leader's gender: 0=male, 1=female, 2=neuter */
    Bitfield(nemgend, 2); /* nemesis's gender */
    Bitfield(godgend, 2); /* deity's gender */

    /* keep track of leader presence/absence even if leader is
       polymorphed, raised from dead, etc */
    Bitfield(leader_is_dead, 1);
    unsigned leader_m_id;
};

#define MAX_QUEST_TRIES 7  /* exceed this and you "fail" */
#define MIN_QUEST_ALIGN 20 /* at least this align.record to start */
/* note: align 20 matches "pious" as reported by enlightenment (cmd.c) */
#define MIN_QUEST_LEVEL 14 /* at least this u.ulevel to start */
/* note: exp.lev. 14 is threshold level for 5th rank (class title, role.c) */

#define ModeAllowsPostToForum (!wizard && !CasualMode && !ModernMode && !discover)
#if !defined(DEBUG)
#define IfModeAllowsPostToForum if (ModeAllowsPostToForum)
#else
#define IfModeAllowsPostToForum 
#endif
#endif /* QUEST_H */
