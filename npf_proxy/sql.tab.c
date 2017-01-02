
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sql.y"

#include <assert.h>
#include "adlist.h"
#include "sql.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

Stmt *stmtArray[2000];
int indexArray = 0;
Stmt *curStmt = NULL;

//int yydebug=1; 

void yyerror(char *s, ...);
void debug(char *s, ...);

/* for simple function */
#define NORMAL_FUNCTION(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        i->right = (yyvsp[(3) - (4)].item);\
        (yyval.item) = i;}\
        while(0)

#define NORMAL_FUNCTION_ONE_PARAM(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        i->token2 = UNIQUE;\
        i->right = (yyvsp[(3) - (4)].item);\
        (yyval.item) = i;}\
        while(0)

#define NORMAL_FUNCTION_DISTINCT(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        i->token2 = DISTINCT;\
        i->right = (yyvsp[(4) - (5)].item);\
        (yyval.item) = i;}\
        while(0)

#define NORMAL_FUNCTION_ANY_PARAM(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        i->right = (yyvsp[(3) - (4)].item);\
        (yyval.item) = i;}\
        while(0)

#define NORMAL_FUNCTION_WILD(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        i->name = strdup("*");\
        (yyval.item) = i;}\
        while(0)

#define NORMAL_FUNCTION_NO_PARAM(f) do {\
        debug ("CALL %s", #f);\
        Item *i = calloc(1, sizeof(*i));\
        i->token1 = f;\
        (yyval.item) = i;}\
        while(0)

// extern int yydebug = 1;



/* Line 189 of yacc.c  */
#line 147 "sql.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LIST = 258,
     NAME = 259,
     FUNCTION = 260,
     STRING = 261,
     INTNUM = 262,
     BOOL = 263,
     APPROXNUM = 264,
     USERVAR = 265,
     ASSIGN = 266,
     OR = 267,
     XOR = 268,
     ANDOP = 269,
     REGEXP = 270,
     LIKE = 271,
     IS = 272,
     IN = 273,
     NOT = 274,
     BETWEEN = 275,
     COMPARISON = 276,
     SHIFT = 277,
     MOD = 278,
     UMINUS = 279,
     ACCESSIBLE = 280,
     ADD_SQL = 281,
     ALL = 282,
     ALTER = 283,
     ANALYZE = 284,
     AND = 285,
     ANY = 286,
     AS = 287,
     ASENSITIVE = 288,
     ASC = 289,
     BEFORE = 290,
     BIGINT = 291,
     BINARY = 292,
     BIT = 293,
     BLOB = 294,
     BOTH = 295,
     BY = 296,
     CALL = 297,
     CASCADE = 298,
     CASE = 299,
     CHANGE = 300,
     CHAR = 301,
     CHECK = 302,
     COLLATE = 303,
     COLUMN = 304,
     CONDITION = 305,
     CONSTRAINT = 306,
     CONTINUE = 307,
     CONVERT = 308,
     CREATE = 309,
     CROSS = 310,
     CURRENT_DATE = 311,
     CURRENT_TIME = 312,
     CURRENT_TIMESTAMP = 313,
     CURRENT_USER = 314,
     CURSOR = 315,
     DATABASE = 316,
     DATABASES = 317,
     DAY_HOUR = 318,
     DAY_MICROSECOND = 319,
     DAY_MINUTE = 320,
     DAY_SECOND = 321,
     DECIMAL = 322,
     DECLARE = 323,
     DEFAULT = 324,
     DELAYED = 325,
     DELETE_SQL = 326,
     DESC = 327,
     DETERMINISTIC = 328,
     DISTINCT = 329,
     DISTINCTROW = 330,
     DIV = 331,
     DOUBLE = 332,
     DROP = 333,
     DUAL = 334,
     EACH = 335,
     ELSE = 336,
     ELSEIF = 337,
     ENCLOSED = 338,
     ENUM = 339,
     ESCAPED = 340,
     EXISTS = 341,
     EXIT = 342,
     EXPLAIN = 343,
     FALSE = 344,
     FETCH = 345,
     FLOAT = 346,
     FOR = 347,
     FORCE = 348,
     FOREIGN = 349,
     FROM = 350,
     FULLTEXT = 351,
     GRANT = 352,
     GROUP = 353,
     HAVING = 354,
     HIGH_PRIORITY = 355,
     HOUR_MICROSECOND = 356,
     HOUR_MINUTE = 357,
     HOUR_SECOND = 358,
     IF = 359,
     IGNORE = 360,
     INDEX = 361,
     INFILE = 362,
     INNER = 363,
     INOUT = 364,
     INSENSITIVE = 365,
     INSERT = 366,
     INT = 367,
     INTEGER = 368,
     INTERVAL = 369,
     INTO = 370,
     ITERATE = 371,
     JOIN = 372,
     KEY = 373,
     KEYS = 374,
     KILL = 375,
     LEADING = 376,
     LEAVE = 377,
     LEFT = 378,
     LIMIT = 379,
     LINES = 380,
     LINER = 381,
     LOAD = 382,
     LOCALTIME = 383,
     LOCALTIMESTAMP = 384,
     LOCK = 385,
     LONG = 386,
     LONGBLOB = 387,
     LONGTEXT = 388,
     LOOP = 389,
     LOW_PRIORITY = 390,
     MEDIUMBLOB = 391,
     MEDIUMINT = 392,
     MEDIUMTEXT = 393,
     MINUTE_MICROSECOND = 394,
     MINUTE_SECOND = 395,
     MODE = 396,
     MODIFIES = 397,
     NATURAL = 398,
     NO_WRITE_TO_BINLOG = 399,
     NULLX = 400,
     NUMERIC = 401,
     ON = 402,
     ONDUPLICATE = 403,
     OPTIMIZE = 404,
     OPTION = 405,
     OPTIONALLY = 406,
     ORDER = 407,
     OUT = 408,
     OUTER = 409,
     OUTFILE = 410,
     PRECISION = 411,
     PRIMARY = 412,
     PROCEDURE = 413,
     PURGE = 414,
     READ = 415,
     READS = 416,
     REAL = 417,
     REFERENCES = 418,
     RELEASE = 419,
     RENAME = 420,
     REPEAT = 421,
     REPLACE = 422,
     REQUIRE = 423,
     RESTRICT = 424,
     RETURN = 425,
     REVOKE = 426,
     RIGHT = 427,
     SCHEMA = 428,
     SCHEMAS = 429,
     SECOND_MICROSECOND = 430,
     SELECT = 431,
     SENSITIVE = 432,
     SEPARATOR = 433,
     SET = 434,
     SETNAMES = 435,
     SETCHARACTER = 436,
     SETTRAN = 437,
     SETPASSWORD = 438,
     SETOPTION = 439,
     SHARE = 440,
     SHOW = 441,
     SHOWVARIABLES = 442,
     SHOWCOLLATION = 443,
     SMALLINT = 444,
     SPATIAL = 445,
     SPECIFIC = 446,
     SQL = 447,
     SQLEXCEPTION = 448,
     SQLSTATE = 449,
     SQLWARNING = 450,
     SQL_BIG_RESULT = 451,
     SQL_CALC_FOUND_ROWS = 452,
     SQL_SMALL_RESULT = 453,
     SSL = 454,
     STARTING = 455,
     STRAIGHT_JOIN = 456,
     TABLE = 457,
     TRUE = 458,
     TERMINATED = 459,
     THEN = 460,
     TINYBLOB = 461,
     TINYINT = 462,
     TINYTEXT = 463,
     TRUNCATE = 464,
     TO = 465,
     TRAILING = 466,
     TRIGGER = 467,
     UNDO = 468,
     UNION = 469,
     UNIQUE = 470,
     UNLOCK = 471,
     UNSIGNED = 472,
     UPDATE = 473,
     USAGE = 474,
     USE = 475,
     USING = 476,
     UTC_DATE = 477,
     UTC_TIME = 478,
     UTC_TIMESTAMP = 479,
     VALUES = 480,
     VARBINARY = 481,
     VARCHAR = 482,
     VARYING = 483,
     WHEN = 484,
     WHERE = 485,
     WHILE = 486,
     WITH = 487,
     WRITE = 488,
     X509 = 489,
     YEAR_MONTH = 490,
     ZEROFILL = 491,
     FSTART = 492,
     FABS = 493,
     FACOS = 494,
     FADDTIME = 495,
     FAES_DECRYPT = 496,
     FAES_ENCRYPT = 497,
     FAREA = 498,
     FASBINARY = 499,
     FASIN = 500,
     FASTEXT = 501,
     FASWKB = 502,
     FASWKT = 503,
     FATAN = 504,
     FATAN2 = 505,
     FASCII = 506,
     FAVG = 507,
     FADDDATE = 508,
     FBENCHMARK = 509,
     FBIN = 510,
     FBIT_AND = 511,
     FBIT_OR = 512,
     FBIT_XOR = 513,
     FBIT_COUNT = 514,
     FBIT_LENGTH = 515,
     FCAST = 516,
     FCEILING = 517,
     FCENTROID = 518,
     FCHAR = 519,
     FCHARACTER_LENGTH = 520,
     FCOERCIBILITY = 521,
     FCOMPRESS = 522,
     FCONCAT = 523,
     FCONCAT_WS = 524,
     FCONNECTION_ID = 525,
     FCONV = 526,
     FCONVERT_TZ = 527,
     FCOS = 528,
     FCOT = 529,
     FCRC32 = 530,
     FCROSSESS = 531,
     FCOUNT = 532,
     FCHARSET = 533,
     FCOLLATION = 534,
     FCURRENT_USER = 535,
     FCURDATE = 536,
     FCURRENT_DATE = 537,
     FCURTIME = 538,
     FCURTIME_TIME = 539,
     FCURRENT_TIMESTAMP = 540,
     FDATE = 541,
     FDATEDIFF = 542,
     FDATENAME = 543,
     FDATEOFMONTH = 544,
     FDATEOFWEEK = 545,
     FDATEOFYEAR = 546,
     FDATE_ADD = 547,
     FDATE_SUB = 548,
     FDATE_FORMAT = 549,
     FDATABASE = 550,
     FDAY = 551,
     FDAYNAME = 552,
     FDAYOFMONTH = 553,
     FDAYOFWEEK = 554,
     FDAYOFYEAR = 555,
     FDEFAULT = 556,
     FDECODE = 557,
     FDEGREES = 558,
     FDES_DECRYPT = 559,
     FDES_ENCRYPT = 560,
     FDIMENSION = 561,
     FISJOINT = 562,
     FELT = 563,
     FENCODE = 564,
     FENCRYPT = 565,
     FENDPOINT = 566,
     FENVELOPE = 567,
     FEQUALS = 568,
     FEXP = 569,
     FEXPORT_SET = 570,
     FEXTRACT = 571,
     FEXTERIORRING = 572,
     FEXTRACTVALUE = 573,
     FFIELD = 574,
     FFIND_IN_SET = 575,
     FFLOOR = 576,
     FFORMAT = 577,
     FFOUND_ROWS = 578,
     FFROM_DAYS = 579,
     FFROM_UNIXTIME = 580,
     FGET_FORMAT = 581,
     FGEOMCOLLFROMTEXT = 582,
     FGEOMCOLLFROMWKB = 583,
     FGEOMETRYCOLLECTIONFROMTEXT = 584,
     FGEOMETRYCOLLECTIONFROMWKB = 585,
     FGEOMETRYFROMTEXT = 586,
     FGEOMETRYFROMWKB = 587,
     FGEOMETRYN = 588,
     FGEOMETRYTYPE = 589,
     FGEOMFROMTEXT = 590,
     FGEOMFROMWKB = 591,
     FGET_LOCK = 592,
     FGLENGTH = 593,
     FGREATEST = 594,
     FHEX = 595,
     FHOUR = 596,
     FINSERT = 597,
     FINSTR = 598,
     FIFNULL = 599,
     FIF = 600,
     FINET_ATON = 601,
     FINET_NTOA = 602,
     FINTERIORRINGN = 603,
     FINTERSECTS = 604,
     FISCLOSED = 605,
     FISEMPTY = 606,
     FISNULL = 607,
     FISSIMPLE = 608,
     FIS_FREE_LOCK = 609,
     FIS_USED_LOCK = 610,
     FLAST_DAY = 611,
     FLAST_INSERT_ID = 612,
     FLCASE = 613,
     FLEFT = 614,
     FLENGTH = 615,
     FLINEFROMTEXT = 616,
     FLINEFROMWKB = 617,
     FLINESTRINGFROMTEXT = 618,
     FLINESTRINGFROMWKB = 619,
     FLN = 620,
     FLOAD_FILE = 621,
     FLOCATE = 622,
     FLOG = 623,
     FLOG10 = 624,
     FLOG2 = 625,
     FLOWER = 626,
     FLPAD = 627,
     FLTRIM = 628,
     FLOCALTIME = 629,
     FLOCALTIMESTAMP = 630,
     FMAKEDATE = 631,
     FMAKETIME = 632,
     FMAKE_SET = 633,
     FMASTER_POS_WAIT = 634,
     FMBRCONTAINS = 635,
     FMBRDISJOINT = 636,
     FMBREQUAL = 637,
     FMBRINTERSECTS = 638,
     FMBROVERLAPS = 639,
     FMBRTOUCHES = 640,
     FMBRWITHIN = 641,
     FMD5 = 642,
     FMLINEFROMTEXT = 643,
     FMLINEFROMWKB = 644,
     FMONTHNAME = 645,
     FMPOINTFROMTEXT = 646,
     FMPOINTFROMWKB = 647,
     FMPOLYFROMTEXT = 648,
     FMPOLYFROMWKB = 649,
     FMULTILINESTRINGFROMTEXT = 650,
     FMULTILINESTRINGFROMWKB = 651,
     FMULTIPOINTFROMTEXT = 652,
     FMULTIPOINTFROMWKB = 653,
     FMULTIPOLYGONFROMTEXT = 654,
     FMULTIPOLYGONFROMWKB = 655,
     FMICROSECOND = 656,
     FMINUTE = 657,
     FMONTH = 658,
     FGROUP_CONCAT = 659,
     FAGAINST = 660,
     FMATCH = 661,
     FMAX = 662,
     FMID = 663,
     FMIN = 664,
     FMOD = 665,
     FNOW = 666,
     FNAME_CONST = 667,
     FNULLIF = 668,
     FNUMGEOMETRIES = 669,
     FNUMINTERIORRINGS = 670,
     FNUMPOINTS = 671,
     FOCT = 672,
     FOCTET_LENGTH = 673,
     FORD = 674,
     FOVERLAPS = 675,
     FOLD_PASSWORD = 676,
     FPERIOD_ADD = 677,
     FPERIOD_DIFF = 678,
     FPI = 679,
     FPOSITION = 680,
     FPASSWORD = 681,
     FPOINTFROMTEXT = 682,
     FPOINTFROMWKB = 683,
     FPOINTN = 684,
     FPOLYFROMTEXT = 685,
     FPOLYFROMWKB = 686,
     FPOLYGONFROMTEXT = 687,
     FPOLYGONFROMWKB = 688,
     FPOWER = 689,
     FQUARTER = 690,
     FQUOTE = 691,
     FRADIANS = 692,
     FRAND = 693,
     FROUND = 694,
     FROW_COUNT = 695,
     FREPEAT = 696,
     FREPLACE = 697,
     FREVERSE = 698,
     FRIGHT = 699,
     FRPAD = 700,
     FRTRIM = 701,
     FRELEASE_LOCK = 702,
     FSEC_TO_TIME = 703,
     FSEC_TO_DATE = 704,
     FSHA = 705,
     FSHA1 = 706,
     FSLEEP = 707,
     FSCHEMA = 708,
     FSOUNDEX = 709,
     FSPACE = 710,
     FSQRT = 711,
     FSRID = 712,
     FSTARTPOINT = 713,
     FSTRCMP = 714,
     FSTR_TO_DATE = 715,
     FSECOND = 716,
     FSUBTIME = 717,
     FSIGN = 718,
     FSIN = 719,
     FSUBSTRING = 720,
     FSUBSTRING_INDEX = 721,
     FSESSION_USER = 722,
     FSTD = 723,
     FSTDDEV = 724,
     FSTDDEV_POP = 725,
     FSTDDEV_SAMP = 726,
     FSUBDATE = 727,
     FSUM = 728,
     FSYSDATE = 729,
     FSYSTEM_USER = 730,
     FTAN = 731,
     FTIMEDIFF = 732,
     FTIME_FORMAT = 733,
     FTIME_TO_SEC = 734,
     FTRUNCATE = 735,
     FTOUCHES = 736,
     FTO_DAYS = 737,
     FTRIM = 738,
     FTIME = 739,
     FTIMESTAMP = 740,
     FTIMESTAMPADD = 741,
     FTIMESTAMPDIFF = 742,
     FVARIANCE = 743,
     FVAR_POP = 744,
     FVAR_SAMP = 745,
     FUCASE = 746,
     FUNCOMPRESS = 747,
     FUNCOMPRESSED_LENGTH = 748,
     FUNHEX = 749,
     FUSER = 750,
     FUNIX_TIMESTAMP = 751,
     FUPDATEXML = 752,
     FUPPER = 753,
     FUUID = 754,
     FUUID_SHORT = 755,
     FVERSION = 756,
     FUTC_DATE = 757,
     FUTC_TIME = 758,
     FUTC_TIMESTAMP = 759,
     FWEEK = 760,
     FWEEKDAY = 761,
     FWEEKOFYEAR = 762,
     FYEAR = 763,
     FYEARWEEK = 764,
     FX = 765,
     FY = 766,
     FEND = 767,
     SUB_OP = 768,
     ADD_OP = 769,
     MUL_OP = 770,
     DIV_OP = 771,
     BITOR_OP = 772,
     BITXOR_OP = 773,
     BITAND_OP = 774
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "sql.y"

    int intval;
    double floatval;
    char *strval;
    int subtok;
    list* listval;
    Item* item;
    Table* tableval;
    Stmt *stmt;



/* Line 214 of yacc.c  */
#line 715 "sql.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 670 "sql.y"


void stmtInit(Stmt *stmt) {
    stmt->joinList = listCreate();
    stmt->groupList = listCreate();
    stmt->havingList = listCreate();
    stmt->orderList = listCreate();
    stmt->limitList = listCreate();
    stmt->setList = listCreate();
    stmt->updateSetList = listCreate();
    stmt->select_expr_list = listCreate();
    stmt->whereList = listCreate();
    stmt->insertList = listCreate();
    stmt->valueList  = listCreate();
    stmt->usingList = listCreate();
}

 void resolve_prefix(Item * i, Stmt * stmt){
   
        listIter *iter1 = NULL, *iter2 = NULL, *iter3 = NULL;
        listNode *node1 = NULL, *node2 = NULL, *node3 = NULL;

	/* Case A: Search Tables to Resolve (Potential) Alias */
	if(i->prefix){
	  iter2 = listGetIterator(stmt->joinList, AL_START_HEAD); 
	  node2 = listNext(iter2);
	  while (node2 != NULL) {
	    /* This is a table reference */
	    /* It's important char * fields are db, name, and alias */
	    /* It also has the Stmt * sub field for subqueries */
	    Table *t = (Table *)listNodeValue(node2);
	    
	    if(t->alias && !strcmp(i->prefix,t->alias)){
	      /* Case A.1 -- There is an alias, but not a subquery */
	      if(t->name){
		debug("Handling alias to a table name");
		/* Remove alias from item, replace with actual table name */
		free(i->prefix);
		i->prefix = strdup(t->name);
		
		/* If db is listed in table reference, why not pass it up? */
		if(t->db)
		  i->db = strdup(t->db);
	      }
	      /* Case A.2 -- There is an alias and it is a subquery */
	      else if(t->sub){
		debug("Handling alias to a subquery");
		/* At this point the subqueries fields will have already been resolved */
		/* All we need to do is look through the selected expressions for a match */
		iter3 = listGetIterator(t->sub->select_expr_list, AL_START_HEAD); 
		node3 = listNext(iter3);
		while (node3 != NULL) {
		  Item *s = (Item *)listNodeValue(node3);
		  
		  /* Case A.2.1 main: "select X.Y" --> sub: "(SELECT t.a AS Y FROM t) AS X" */
		  if(s->alias && !strcmp(i->name,s->alias)){
		    free(i->prefix);
		    i->prefix = strdup(s->prefix);
		    
		    /* If db is listed in table reference, why not pass it up? */
		    if(s->db)
		      i->db = strdup(s->db);		
		    
		    /* Short circuit iteration */	    
		    node3 = NULL;
		  }
		  /* Case A.2.2 main: "select X.Y" --> sub: "(SELECT t.a FROM t) AS X" */
		  else if(s->name && !strcmp(i->name,s->name)){
		    free(i->prefix);
		    i->prefix = strdup(s->prefix);
		    
		    /* If db is listed in table reference, why not pass it up? */
		    if(s->db)
		      i->db = strdup(s->db);
		    
		    /* Short circuit iteration */	    
		    node3 = NULL;
		  }
		  else
		    node3 = listNext(iter3);
		}
	      }
	      /* Case A.3 -- I believe this is an unreachable case */
	      else
		debug ("Unhandled case\n");
	      	      
	      /* Short circuit iteration */	    
	      node2 = NULL;
	    }
	    else
	      node2 = listNext(iter2);
	  }
	  listReleaseIterator(iter2);
	}
	/* Case B -- If item does not have a prefix, it is an unambigious reference 
	   to the lone table in the FROM clause */
	else{
	  /* Pop the first table and assign it to the item */
	  iter2 = listGetIterator(stmt->joinList, AL_START_HEAD); 
	  node2 = listNext(iter2);
	  Table *t = (Table *)listNodeValue(node2);
	  debug ("(Assuming this item corresponds to lone table %s.%s)",
		 t->db,t->name);
	  free(i->prefix);
	  i->prefix = strdup(t->name);
	  
	  /* If db is listed in table reference, why not pass it up? */
	  if(t->db)
	    i->db = strdup(t->db);
	  listReleaseIterator(iter2);
	}
 }
 void resolve_select_expr_rec(Item * i, Stmt * stmt);

 void resolve_select_expr_rec_list(list *l, Stmt * stmt){
    if (!l) return;
    if (listLength(l) == 0) return ;

    listIter *iter = NULL;
    listNode *node = NULL;
    iter = listGetIterator(l, AL_START_HEAD); 
    while ((node = listNext(iter)) != NULL) {
        Item *i = (Item *)listNodeValue(node);
	resolve_select_expr_rec(i,stmt);
    }
    listReleaseIterator(iter);

 }
 void resolve_select_expr_rec(Item * i, Stmt * stmt){
  if(!i)
    {return;}

  debug("Here i am, about to resolve a select expr rec\n");
  debug("i is %p, which is a %c in c, and of size %d\n",i,i,sizeof(*i));
  debug("token1 is %p\n",i->token1);

  if(i->token1 == NAME){
    debug("Column %s.%s.%s is actually...",i->db,i->prefix,i->name);
    resolve_prefix(i,stmt);
    debug("\t...from table %s.%s.%s\n",i->db,i->prefix,i->name);
  }

  /* Handle i->left. This always appears to be a normal field or null, never a list */
  if (i->left) {
    resolve_select_expr_rec(i->left,stmt);
  }
  
  /* For CASE only, might need to pop items in this i->next field:*/
  if( i->token1 == CASE && i->next) {
    resolve_select_expr_rec(i->next,stmt);
  } 
  /* Handle i-> right. All cases in print_expr boil down to this: */
  if (i->right){
    if((i->token1 > FSTART) 
       && (i->token1 < FEND)
       && (i->token2 != UNIQUE) )
      resolve_select_expr_rec_list((list *)i->right,stmt);
    else
      resolve_select_expr_rec(i->right,stmt);
  }
 }

 void resolve_select_expr(Stmt * stmt){
      listIter *iter1 = NULL, *iter2 = NULL, *iter3 = NULL;
      listNode *node1 = NULL, *node2 = NULL, *node3 = NULL;

      /* RESOLVE COLUMNS READ */
      iter1 = listGetIterator(stmt->select_expr_list, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

      /* RESOLVE COLUMNS USED (ALL CLAUSES) */
      iter1 = listGetIterator(stmt->whereList, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

      iter1 = listGetIterator(stmt->groupList, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

      iter1 = listGetIterator(stmt->havingList, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

      iter1 = listGetIterator(stmt->orderList, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

      iter1 = listGetIterator(stmt->limitList, AL_START_HEAD); 
      while ((node1 = listNext(iter1)) != NULL) {
	/* This is a column reference basically */
	/* It's important char * fields are prefix, name, and alias */
	Item *i = (Item *)listNodeValue(node1);	
	resolve_select_expr_rec(i,stmt);
      }
      listReleaseIterator(iter1);	

 }

  

/* Line 264 of yacc.c  */
#line 954 "sql.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9695

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  534
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1783

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   774

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,     2,     2,    30,    24,     2,
     532,   533,    28,    26,   530,    27,   531,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   529,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    22,    25,    31,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    14,    16,    20,    32,
      33,    36,    37,    42,    45,    50,    51,    53,    55,    56,
      59,    60,    63,    64,    68,    71,    76,    77,    80,    85,
      86,    89,    91,    95,    96,    99,   102,   105,   108,   111,
     114,   117,   120,   122,   126,   128,   131,   135,   139,   141,
     145,   147,   149,   153,   159,   163,   167,   169,   170,   173,
     174,   180,   184,   190,   197,   203,   204,   206,   208,   209,
     211,   213,   215,   218,   221,   222,   224,   225,   227,   230,
     235,   242,   249,   256,   263,   270,   277,   278,   281,   282,
     284,   286,   290,   294,   296,   298,   306,   316,   319,   322,
     323,   330,   333,   338,   339,   342,   350,   352,   354,   356,
     365,   376,   377,   382,   383,   386,   389,   392,   395,   397,
     398,   399,   403,   407,   413,   415,   419,   427,   437,   445,
     455,   457,   459,   461,   463,   472,   483,   491,   501,   509,
     519,   521,   523,   532,   533,   536,   539,   541,   543,   545,
     549,   555,   561,   569,   571,   576,   581,   582,   585,   587,
     596,   607,   617,   624,   636,   645,   647,   651,   652,   657,
     663,   668,   673,   679,   685,   686,   690,   693,   697,   701,
     705,   709,   712,   718,   722,   726,   729,   733,   734,   738,
     744,   745,   747,   748,   751,   754,   755,   760,   764,   767,
     771,   775,   779,   783,   787,   791,   795,   799,   803,   807,
     811,   817,   820,   825,   827,   829,   831,   833,   837,   841,
     845,   851,   857,   859,   863,   867,   868,   870,   872,   873,
     875,   877,   879,   881,   884,   888,   892,   895,   897,   899,
     902,   904,   907,   909,   912,   917,   919,   922,   927,   929,
     931,   933,   935,   937,   940,   943,   948,   952,   954,   956,
     958,   962,   965,   966,   968,   970,   972,   974,   978,   982,
     984,   986,   990,   992,   994,   996,   998,  1002,  1006,  1010,
    1014,  1018,  1022,  1026,  1030,  1034,  1037,  1041,  1045,  1049,
    1053,  1059,  1066,  1073,  1080,  1084,  1088,  1092,  1096,  1099,
    1102,  1106,  1110,  1114,  1119,  1123,  1127,  1132,  1138,  1140,
    1144,  1145,  1147,  1153,  1160,  1166,  1173,  1178,  1183,  1188,
    1193,  1198,  1203,  1208,  1213,  1218,  1223,  1228,  1233,  1238,
    1243,  1248,  1253,  1258,  1264,  1269,  1274,  1279,  1284,  1289,
    1294,  1299,  1304,  1309,  1314,  1319,  1324,  1329,  1334,  1339,
    1344,  1349,  1353,  1358,  1363,  1368,  1373,  1378,  1383,  1389,
    1394,  1399,  1404,  1409,  1413,  1417,  1421,  1425,  1429,  1433,
    1438,  1443,  1448,  1453,  1458,  1463,  1468,  1472,  1477,  1482,
    1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,  1527,  1532,
    1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,  1577,  1582,
    1587,  1592,  1597,  1602,  1607,  1611,  1616,  1621,  1626,  1631,
    1636,  1641,  1646,  1651,  1656,  1661,  1666,  1671,  1676,  1681,
    1686,  1691,  1696,  1701,  1706,  1711,  1716,  1721,  1726,  1731,
    1736,  1741,  1746,  1751,  1756,  1761,  1766,  1771,  1776,  1780,
    1785,  1790,  1795,  1800,  1805,  1810,  1815,  1820,  1825,  1830,
    1835,  1840,  1845,  1850,  1855,  1860,  1865,  1869,  1873,  1878,
    1883,  1888,  1893,  1898,  1903,  1908,  1913,  1918,  1923,  1928,
    1933,  1938,  1943,  1948,  1953,  1958,  1963,  1968,  1973,  1978,
    1983,  1988,  1993,  1998,  2003,  2008,  2013,  2018,  2023,  2028,
    2033,  2038,  2043,  2048,  2052,  2057,  2062,  2067,  2072,  2077,
    2082,  2087,  2092,  2097,  2102,  2107,  2112,  2116,  2121,  2126,
    2131,  2136,  2141,  2146,  2151,  2156,  2161,  2166,  2171,  2176,
    2180,  2185,  2190,  2194,  2199,  2204,  2209,  2214,  2219,  2224,
    2229,  2234,  2239,  2244,  2249,  2254,  2259,  2264,  2268,  2273,
    2278,  2283,  2288,  2293,  2298,  2303,  2308,  2313,  2318,  2323,
    2327,  2332,  2337,  2342,  2347,  2352,  2357,  2363,  2367,  2371,
    2376,  2381,  2386,  2391,  2396,  2401,  2406,  2411,  2416,  2421,
    2426,  2431,  2436,  2441,  2446,  2451,  2456,  2461,  2466,  2470,
    2474,  2479,  2484,  2489,  2493,  2498,  2502,  2506,  2510,  2514,
    2519,  2524,  2529,  2534,  2539,  2544,  2549,  2556,  2565,  2573,
    2578,  2580,  2582,  2584,  2591,  2598,  2602,  2606,  2610,  2614,
    2618,  2622,  2626,  2630,  2634,  2638,  2642,  2646,  2651,  2658,
    2662,  2668,  2673,  2679,  2683,  2688,  2692,  2697
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     535,     0,    -1,     1,    -1,   536,   529,    -1,   535,   536,
     529,    -1,   538,    -1,   185,    -1,   537,   550,   551,    -1,
     537,   550,   551,   104,   553,   539,   540,   544,   545,   547,
     548,    -1,    -1,   239,   622,    -1,    -1,   107,    50,   541,
     543,    -1,   622,   542,    -1,   541,   530,   622,   542,    -1,
      -1,    43,    -1,    81,    -1,    -1,   241,     4,    -1,    -1,
     108,   622,    -1,    -1,   161,    50,   546,    -1,   622,   542,
      -1,   546,   530,   622,   542,    -1,    -1,   133,   622,    -1,
     133,   622,   530,   622,    -1,    -1,   124,   549,    -1,     4,
      -1,   549,   530,     4,    -1,    -1,   550,    36,    -1,   550,
      83,    -1,   550,    84,    -1,   550,   109,    -1,   550,   210,
      -1,   550,   207,    -1,   550,   205,    -1,   550,   206,    -1,
     552,    -1,   551,   530,   552,    -1,    28,    -1,   591,   557,
      -1,     4,   531,    28,    -1,     4,   532,   533,    -1,   554,
      -1,   553,   530,   554,    -1,   555,    -1,   558,    -1,     4,
     557,   566,    -1,     4,   531,     4,   557,   566,    -1,   569,
     556,     4,    -1,   532,   553,   533,    -1,    41,    -1,    -1,
     556,     4,    -1,    -1,   554,   559,   126,   555,   563,    -1,
     554,   210,   555,    -1,   554,   210,   555,   156,   622,    -1,
     554,   561,   560,   126,   555,   565,    -1,   554,   152,   562,
     126,   555,    -1,    -1,   117,    -1,    64,    -1,    -1,   163,
      -1,   132,    -1,   181,    -1,   132,   560,    -1,   181,   560,
      -1,    -1,   565,    -1,    -1,   230,    -1,   156,   622,    -1,
     564,   532,   549,   533,    -1,   229,   127,   567,   532,   568,
     533,    -1,   114,   127,   567,   532,   568,   533,    -1,   102,
     127,   567,   532,   568,   533,    -1,   229,   115,   567,   532,
     568,   533,    -1,   114,   115,   567,   532,   568,   533,    -1,
     102,   115,   567,   532,   568,   533,    -1,    -1,   101,   126,
      -1,    -1,     4,    -1,   166,    -1,   568,   530,     4,    -1,
     532,   538,   533,    -1,   571,    -1,    80,    -1,   570,   572,
     104,     4,   539,   545,   547,    -1,   570,   572,   104,     4,
     531,     4,   539,   545,   547,    -1,   572,   144,    -1,   572,
     114,    -1,    -1,   570,   572,   573,   104,   553,   539,    -1,
       4,   574,    -1,   573,   530,     4,   574,    -1,    -1,   531,
      28,    -1,   570,   572,   104,   573,   230,   553,   539,    -1,
     577,    -1,   120,    -1,   234,    -1,   575,   579,   580,     4,
     581,   576,   582,   578,    -1,   575,   579,   580,     4,   531,
       4,   581,   576,   582,   578,    -1,    -1,   157,   127,   227,
     584,    -1,    -1,   579,   144,    -1,   579,    79,    -1,   579,
     109,    -1,   579,   114,    -1,   124,    -1,    -1,    -1,   532,
     549,   533,    -1,   532,   583,   533,    -1,   582,   530,   532,
     583,   533,    -1,   591,    -1,   583,   530,   591,    -1,   575,
     579,   580,     4,   188,   584,   578,    -1,   575,   579,   580,
       4,   531,     4,   188,   584,   578,    -1,   575,   579,   580,
       4,   581,   538,   578,    -1,   575,   579,   580,     4,   531,
       4,   581,   538,   578,    -1,   618,    -1,   587,    -1,   176,
      -1,   234,    -1,   585,   579,   580,     4,   581,   586,   582,
     578,    -1,   585,   579,   580,     4,   531,     4,   581,   586,
     582,   578,    -1,   585,   579,   580,     4,   188,   584,   578,
      -1,   585,   579,   580,     4,   531,     4,   188,   584,   578,
      -1,   585,   579,   580,     4,   581,   538,   578,    -1,   585,
     579,   580,     4,   531,     4,   581,   538,   578,    -1,   589,
      -1,   227,    -1,   588,   590,   553,   188,   592,   539,   545,
     547,    -1,    -1,   579,   144,    -1,   579,   114,    -1,   154,
      -1,   622,    -1,    78,    -1,     4,    22,   591,    -1,     4,
     531,     4,    22,   591,    -1,   592,   530,     4,    22,   591,
      -1,   592,   530,     4,   531,     4,    22,   591,    -1,   593,
      -1,    63,    70,   594,     4,    -1,    63,   182,   594,     4,
      -1,    -1,   113,    95,    -1,   595,    -1,    63,   608,   211,
     594,     4,   532,   596,   533,    -1,    63,   608,   211,   594,
       4,   531,     4,   532,   596,   533,    -1,    63,   608,   211,
     594,     4,   532,   596,   533,   606,    -1,    63,   608,   211,
     594,     4,   606,    -1,    63,   608,   211,   594,     4,   531,
       4,   532,   596,   533,   606,    -1,    63,   608,   211,   594,
       4,   531,     4,   606,    -1,   597,    -1,   596,   530,   597,
      -1,    -1,   598,     4,   604,   599,    -1,   166,   127,   532,
     549,   533,    -1,   127,   532,   549,   533,    -1,   115,   532,
     549,   533,    -1,   105,   115,   532,   549,   533,    -1,   105,
     127,   532,   549,   533,    -1,    -1,   599,    20,   154,    -1,
     599,   154,    -1,   599,    78,     6,    -1,   599,    78,     7,
      -1,   599,    78,     9,    -1,   599,    78,     8,    -1,   599,
       4,    -1,   599,   224,   532,   549,   533,    -1,   599,   224,
     127,    -1,   599,   166,   127,    -1,   599,   127,    -1,   599,
       4,     6,    -1,    -1,   532,     7,   533,    -1,   532,     7,
     530,     7,   533,    -1,    -1,    46,    -1,    -1,   602,   226,
      -1,   602,   245,    -1,    -1,   603,    55,   188,     6,    -1,
     603,    57,     6,    -1,     4,   600,    -1,   216,   600,   602,
      -1,   198,   600,   602,    -1,   146,   600,   602,    -1,   121,
     600,   602,    -1,   122,   600,   602,    -1,    45,   600,   602,
      -1,   171,   600,   602,    -1,    86,   600,   602,    -1,   100,
     600,   602,    -1,    76,   600,   602,    -1,    55,   600,   603,
      -1,   236,   532,     7,   533,   603,    -1,    46,   600,    -1,
     235,   532,     7,   533,    -1,   215,    -1,    48,    -1,   145,
      -1,   141,    -1,   217,   601,   603,    -1,   147,   601,   603,
      -1,   142,   601,   603,    -1,    93,   532,   605,   533,   603,
      -1,   188,   532,   605,   533,   603,    -1,     6,    -1,   605,
     530,     6,    -1,   607,   556,   538,    -1,    -1,   114,    -1,
     176,    -1,    -1,     4,    -1,   610,    -1,   196,    -1,   197,
      -1,   609,   539,    -1,   609,    16,     6,    -1,   609,    16,
       4,    -1,     4,     4,    -1,     4,    -1,    10,    -1,     4,
      10,    -1,   612,    -1,   229,     4,    -1,   613,    -1,   218,
       4,    -1,   218,     4,   531,     4,    -1,   614,    -1,    81,
       4,    -1,    81,     4,   531,     4,    -1,   617,    -1,   188,
      -1,     4,    -1,    78,    -1,   154,    -1,   615,   618,    -1,
     189,   616,    -1,   192,   619,    22,   622,    -1,   190,   188,
     616,    -1,   193,    -1,   191,    -1,   621,    -1,   618,   530,
     621,    -1,   101,     4,    -1,    -1,   622,    -1,    46,    -1,
     154,    -1,    78,    -1,   611,    22,   620,    -1,   611,    11,
     622,    -1,     4,    -1,    10,    -1,     4,   531,     4,    -1,
       6,    -1,     7,    -1,     9,    -1,     8,    -1,   622,    26,
     622,    -1,   622,    26,   626,    -1,   622,    27,   626,    -1,
     626,    26,   622,    -1,   622,    27,   622,    -1,   622,    28,
     622,    -1,   622,    29,   622,    -1,   622,    30,   622,    -1,
     622,    31,   622,    -1,    27,   622,    -1,   622,    14,   622,
      -1,   622,    12,   622,    -1,   622,    13,   622,    -1,   622,
      22,   622,    -1,   622,    22,   532,   538,   533,    -1,   622,
      22,    40,   532,   538,   533,    -1,   622,    22,     4,   532,
     538,   533,    -1,   622,    22,    36,   532,   538,   533,    -1,
     622,    23,   622,    -1,   622,    24,   622,    -1,   622,    32,
     622,    -1,   622,    25,   622,    -1,    20,   622,    -1,    19,
     622,    -1,    10,    11,   622,    -1,   532,   622,   533,    -1,
     622,    17,   154,    -1,   622,    17,    20,   154,    -1,   622,
      22,   154,    -1,   622,    17,     8,    -1,   622,    17,    20,
       8,    -1,   622,    21,   622,    39,   622,    -1,   622,    -1,
     622,   530,   623,    -1,    -1,   623,    -1,   622,    18,   532,
     623,   533,    -1,   622,    20,    18,   532,   623,   533,    -1,
     622,    18,   532,   538,   533,    -1,   622,    20,    18,   532,
     538,   533,    -1,    95,   532,   538,   533,    -1,     4,   532,
     624,   533,    -1,   247,   532,   623,   533,    -1,   248,   532,
     623,   533,    -1,   249,   532,   623,   533,    -1,   250,   532,
     623,   533,    -1,   251,   532,   623,   533,    -1,   252,   532,
     623,   533,    -1,   253,   532,   623,   533,    -1,   254,   532,
     623,   533,    -1,   255,   532,   623,   533,    -1,   256,   532,
     623,   533,    -1,   257,   532,   623,   533,    -1,   258,   532,
     623,   533,    -1,   259,   532,   623,   533,    -1,   260,   532,
     623,   533,    -1,   261,   532,   623,   533,    -1,   261,   532,
      83,   623,   533,    -1,   262,   532,   623,   533,    -1,   263,
     532,   623,   533,    -1,   264,   532,   623,   533,    -1,   265,
     532,   623,   533,    -1,   266,   532,   623,   533,    -1,   267,
     532,   623,   533,    -1,   268,   532,   623,   533,    -1,   269,
     532,   623,   533,    -1,   270,   532,   623,   533,    -1,   271,
     532,   623,   533,    -1,   272,   532,   623,   533,    -1,   273,
     532,   623,   533,    -1,   274,   532,   623,   533,    -1,   275,
     532,   623,   533,    -1,   276,   532,   623,   533,    -1,   277,
     532,   623,   533,    -1,   278,   532,   623,   533,    -1,   279,
     532,   533,    -1,   280,   532,   623,   533,    -1,   281,   532,
     623,   533,    -1,   282,   532,   623,   533,    -1,   283,   532,
     623,   533,    -1,   284,   532,   623,   533,    -1,   285,   532,
     623,   533,    -1,   286,   532,    83,   623,   533,    -1,   286,
     532,    28,   533,    -1,   286,   532,   622,   533,    -1,   287,
     532,   623,   533,    -1,   288,   532,   623,   533,    -1,   289,
     532,   533,    -1,   290,   532,   533,    -1,   291,   532,   533,
      -1,   294,   532,   533,    -1,   292,   532,   533,    -1,   293,
     532,   533,    -1,   295,   532,   623,   533,    -1,   296,   532,
     623,   533,    -1,   297,   532,   623,   533,    -1,   298,   532,
     623,   533,    -1,   299,   532,   623,   533,    -1,   300,   532,
     623,   533,    -1,   303,   532,   623,   533,    -1,   304,   532,
     533,    -1,   305,   532,   623,   533,    -1,   306,   532,   623,
     533,    -1,   307,   532,   623,   533,    -1,   308,   532,   623,
     533,    -1,   309,   532,   623,   533,    -1,   310,   532,   623,
     533,    -1,   311,   532,   623,   533,    -1,   312,   532,   623,
     533,    -1,   313,   532,   623,   533,    -1,   314,   532,   623,
     533,    -1,   315,   532,   623,   533,    -1,   316,   532,   623,
     533,    -1,   317,   532,   623,   533,    -1,   318,   532,   623,
     533,    -1,   319,   532,   623,   533,    -1,   320,   532,   623,
     533,    -1,   321,   532,   623,   533,    -1,   322,   532,   623,
     533,    -1,   323,   532,   623,   533,    -1,   324,   532,   623,
     533,    -1,   325,   532,   623,   533,    -1,   326,   532,   623,
     533,    -1,   327,   532,   623,   533,    -1,   328,   532,   623,
     533,    -1,   329,   532,   623,   533,    -1,   330,   532,   623,
     533,    -1,   331,   532,   623,   533,    -1,   332,   532,   533,
      -1,   333,   532,   623,   533,    -1,   334,   532,   623,   533,
      -1,   335,   532,   623,   533,    -1,   336,   532,   623,   533,
      -1,   337,   532,   623,   533,    -1,   338,   532,   623,   533,
      -1,   339,   532,   623,   533,    -1,   340,   532,   623,   533,
      -1,   341,   532,   623,   533,    -1,   342,   532,   623,   533,
      -1,   343,   532,   623,   533,    -1,   344,   532,   623,   533,
      -1,   345,   532,   623,   533,    -1,   346,   532,   623,   533,
      -1,   347,   532,   623,   533,    -1,   348,   532,   623,   533,
      -1,   349,   532,   623,   533,    -1,   350,   532,   623,   533,
      -1,   351,   532,   623,   533,    -1,   352,   532,   623,   533,
      -1,   353,   532,   623,   533,    -1,   354,   532,   623,   533,
      -1,   355,   532,   623,   533,    -1,   356,   532,   623,   533,
      -1,   357,   532,   623,   533,    -1,   358,   532,   623,   533,
      -1,   359,   532,   623,   533,    -1,   360,   532,   623,   533,
      -1,   361,   532,   623,   533,    -1,   362,   532,   623,   533,
      -1,   363,   532,   623,   533,    -1,   364,   532,   623,   533,
      -1,   365,   532,   623,   533,    -1,   366,   532,   533,    -1,
     366,   532,   623,   533,    -1,   367,   532,   623,   533,    -1,
     368,   532,   623,   533,    -1,   369,   532,   623,   533,    -1,
     370,   532,   623,   533,    -1,   371,   532,   623,   533,    -1,
     372,   532,   623,   533,    -1,   373,   532,   623,   533,    -1,
     374,   532,   623,   533,    -1,   375,   532,   623,   533,    -1,
     376,   532,   623,   533,    -1,   377,   532,   623,   533,    -1,
     378,   532,   623,   533,    -1,   379,   532,   623,   533,    -1,
     380,   532,   623,   533,    -1,   381,   532,   623,   533,    -1,
     382,   532,   623,   533,    -1,   383,   532,   533,    -1,   384,
     532,   533,    -1,   385,   532,   623,   533,    -1,   386,   532,
     623,   533,    -1,   387,   532,   623,   533,    -1,   388,   532,
     623,   533,    -1,   389,   532,   623,   533,    -1,   390,   532,
     623,   533,    -1,   391,   532,   623,   533,    -1,   392,   532,
     623,   533,    -1,   393,   532,   623,   533,    -1,   394,   532,
     623,   533,    -1,   395,   532,   623,   533,    -1,   396,   532,
     623,   533,    -1,   397,   532,   623,   533,    -1,   398,   532,
     623,   533,    -1,   399,   532,   623,   533,    -1,   400,   532,
     623,   533,    -1,   401,   532,   623,   533,    -1,   402,   532,
     623,   533,    -1,   403,   532,   623,   533,    -1,   404,   532,
     623,   533,    -1,   405,   532,   623,   533,    -1,   406,   532,
     623,   533,    -1,   407,   532,   623,   533,    -1,   408,   532,
     623,   533,    -1,   409,   532,   623,   533,    -1,   410,   532,
     623,   533,    -1,   411,   532,   623,   533,    -1,   412,   532,
     623,   533,    -1,   413,   532,   623,   533,    -1,   414,   532,
     623,   533,    -1,   415,   532,   623,   533,    -1,   416,   532,
     623,   533,    -1,   417,   532,   623,   533,    -1,   418,   532,
     623,   533,    -1,   419,   532,   623,   533,    -1,   420,   532,
     533,    -1,   421,   532,   623,   533,    -1,   422,   532,   623,
     533,    -1,   423,   532,   623,   533,    -1,   424,   532,   623,
     533,    -1,   425,   532,   623,   533,    -1,   426,   532,   623,
     533,    -1,   427,   532,   623,   533,    -1,   428,   532,   623,
     533,    -1,   429,   532,   623,   533,    -1,   430,   532,   623,
     533,    -1,   431,   532,   623,   533,    -1,   432,   532,   623,
     533,    -1,   433,   532,   533,    -1,   435,   532,   623,   533,
      -1,   436,   532,   623,   533,    -1,   437,   532,   623,   533,
      -1,   438,   532,   623,   533,    -1,   439,   532,   623,   533,
      -1,   440,   532,   623,   533,    -1,   441,   532,   623,   533,
      -1,   442,   532,   623,   533,    -1,   443,   532,   623,   533,
      -1,   444,   532,   623,   533,    -1,   445,   532,   623,   533,
      -1,   446,   532,   623,   533,    -1,   447,   532,   533,    -1,
     447,   532,   623,   533,    -1,   448,   532,   623,   533,    -1,
     449,   532,   533,    -1,   450,   532,   623,   533,    -1,   451,
     532,   623,   533,    -1,   452,   532,   623,   533,    -1,   453,
     532,   623,   533,    -1,   454,   532,   623,   533,    -1,   455,
     532,   623,   533,    -1,   456,   532,   623,   533,    -1,   457,
     532,   623,   533,    -1,   458,   532,   623,   533,    -1,   459,
     532,   623,   533,    -1,   460,   532,   623,   533,    -1,   472,
     532,   623,   533,    -1,   473,   532,   623,   533,    -1,   461,
     532,   623,   533,    -1,   462,   532,   533,    -1,   463,   532,
     623,   533,    -1,   464,   532,   623,   533,    -1,   465,   532,
     623,   533,    -1,   466,   532,   623,   533,    -1,   467,   532,
     623,   533,    -1,   468,   532,   623,   533,    -1,   469,   532,
     623,   533,    -1,   470,   532,   623,   533,    -1,   471,   532,
     623,   533,    -1,   474,   532,   623,   533,    -1,   475,   532,
     623,   533,    -1,   476,   532,   533,    -1,   477,   532,   623,
     533,    -1,   478,   532,   623,   533,    -1,   479,   532,   623,
     533,    -1,   480,   532,   623,   533,    -1,   481,   532,   623,
     533,    -1,   482,   532,   623,   533,    -1,   482,   532,    83,
     623,   533,    -1,   483,   532,   533,    -1,   484,   532,   533,
      -1,   485,   532,   623,   533,    -1,   486,   532,   623,   533,
      -1,   487,   532,   623,   533,    -1,   488,   532,   623,   533,
      -1,   489,   532,   623,   533,    -1,   490,   532,   623,   533,
      -1,   491,   532,   623,   533,    -1,   492,   532,   623,   533,
      -1,   493,   532,   623,   533,    -1,   494,   532,   623,   533,
      -1,   495,   532,   623,   533,    -1,   496,   532,   623,   533,
      -1,   497,   532,   623,   533,    -1,   498,   532,   623,   533,
      -1,   499,   532,   623,   533,    -1,   500,   532,   623,   533,
      -1,   501,   532,   623,   533,    -1,   502,   532,   623,   533,
      -1,   503,   532,   623,   533,    -1,   504,   532,   533,    -1,
     505,   532,   533,    -1,   505,   532,   623,   533,    -1,   506,
     532,   623,   533,    -1,   507,   532,   623,   533,    -1,   508,
     532,   533,    -1,   509,   532,   623,   533,    -1,   510,   532,
     533,    -1,   511,   532,   533,    -1,   512,   532,   533,    -1,
     513,   532,   533,    -1,   514,   532,   623,   533,    -1,   515,
     532,   623,   533,    -1,   516,   532,   623,   533,    -1,   517,
     532,   623,   533,    -1,   518,   532,   623,   533,    -1,   519,
     532,   623,   533,    -1,   520,   532,   623,   533,    -1,   474,
     532,   622,   104,   622,   533,    -1,   474,   532,   622,   104,
     622,   101,   622,   533,    -1,   492,   532,   625,   622,   104,
     623,   533,    -1,   434,   532,   622,   533,    -1,   130,    -1,
     220,    -1,    49,    -1,   301,   532,   622,   530,   626,   533,
      -1,   302,   532,   622,   530,   626,   533,    -1,   123,   622,
      72,    -1,   123,   622,    73,    -1,   123,   622,    74,    -1,
     123,   622,    75,    -1,   123,   622,   244,    -1,   123,   622,
       4,    -1,   123,   622,   110,    -1,   123,   622,   111,    -1,
     123,   622,   112,    -1,   123,   622,   184,    -1,   123,   622,
     148,    -1,   123,   622,   149,    -1,    53,   622,   627,     4,
      -1,    53,   622,   627,    90,   622,     4,    -1,    53,   627,
       4,    -1,    53,   627,    90,   622,     4,    -1,   238,   622,
     214,   622,    -1,   627,   238,   622,   214,   622,    -1,   622,
      16,   622,    -1,   622,    20,    16,   622,    -1,   622,    15,
     622,    -1,   622,    20,    15,   622,    -1,    46,   622,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   902,   902,   906,   911,   921,   925,   936,   941,   954,
     955,   960,   961,   966,   971,   978,   979,   980,   983,   984,
     987,   987,   993,   993,   997,  1003,  1011,  1011,  1015,  1022,
    1023,  1027,  1041,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1068,  1073,  1078,  1086,  1093,  1099,  1109,  1110,
    1113,  1114,  1118,  1132,  1147,  1157,  1160,  1161,  1164,  1165,
    1169,  1171,  1173,  1175,  1177,  1181,  1182,  1183,  1186,  1187,
    1190,  1191,  1194,  1195,  1196,  1199,  1199,  1201,  1206,  1210,
    1214,  1220,  1226,  1232,  1238,  1244,  1250,  1253,  1254,  1257,
    1263,  1268,  1275,  1282,  1285,  1295,  1306,  1318,  1320,  1321,
    1324,  1329,  1330,  1334,  1334,  1336,  1344,  1347,  1360,  1366,
    1377,  1391,  1392,  1395,  1396,  1397,  1398,  1399,  1402,  1402,
    1406,  1407,  1410,  1415,  1421,  1425,  1432,  1442,  1455,  1467,
    1482,  1500,  1503,  1515,  1520,  1530,  1544,  1555,  1568,  1580,
    1595,  1598,  1609,  1622,  1623,  1624,  1628,  1635,  1636,  1646,
    1663,  1681,  1697,  1719,  1723,  1724,  1727,  1728,  1734,  1737,
    1741,  1746,  1751,  1755,  1761,  1766,  1767,  1770,  1770,  1773,
    1774,  1775,  1776,  1777,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,  1791,  1792,  1795,  1796,  1797,
    1800,  1801,  1804,  1805,  1806,  1809,  1810,  1811,  1815,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1852,  1853,  1856,  1859,  1860,  1861,  1864,  1865,
    1869,  1873,  1886,  1900,  1903,  1908,  1916,  1939,  1946,  1953,
    1976,  1978,  1997,  1999,  2016,  2037,  2040,  2056,  2078,  2082,
    2093,  2099,  2104,  2111,  2113,  2132,  2149,  2167,  2183,  2201,
    2205,  2212,  2212,  2214,  2216,  2221,  2226,  2233,  2243,  2257,
    2264,  2271,  2280,  2287,  2293,  2299,  2306,  2312,  2318,  2324,
    2330,  2336,  2342,  2348,  2354,  2360,  2365,  2371,  2377,  2383,
    2390,  2397,  2400,  2401,  2402,  2408,  2414,  2420,  2426,  2431,
    2436,  2442,  2447,  2453,  2460,  2470,  2476,  2485,  2499,  2505,
    2512,  2513,  2516,  2523,  2531,  2541,  2551,  2559,  2572,  2573,
    2575,  2577,  2579,  2580,  2581,  2582,  2583,  2584,  2585,  2586,
    2587,  2588,  2590,  2591,  2593,  2595,  2596,  2597,  2598,  2599,
    2600,  2601,  2603,  2604,  2605,  2607,  2608,  2609,  2610,  2612,
    2613,  2614,  2616,  2618,  2619,  2620,  2621,  2622,  2624,  2625,
    2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,  2634,  2635,
    2637,  2638,  2639,  2640,  2641,  2647,  2648,  2649,  2650,  2651,
    2652,  2653,  2654,  2655,  2656,  2658,  2660,  2661,  2662,  2664,
    2666,  2667,  2668,  2669,  2670,  2671,  2673,  2674,  2675,  2677,
    2679,  2681,  2682,  2684,  2685,  2686,  2687,  2689,  2690,  2691,
    2692,  2693,  2694,  2695,  2696,  2697,  2698,  2699,  2701,  2702,
    2703,  2704,  2705,  2707,  2709,  2711,  2712,  2713,  2714,  2715,
    2716,  2717,  2718,  2719,  2720,  2721,  2722,  2723,  2724,  2725,
    2726,  2728,  2729,  2730,  2731,  2732,  2733,  2734,  2735,  2737,
    2738,  2739,  2740,  2741,  2743,  2744,  2745,  2746,  2748,  2749,
    2751,  2753,  2754,  2755,  2756,  2757,  2758,  2759,  2760,  2761,
    2762,  2763,  2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,
    2772,  2773,  2774,  2775,  2776,  2777,  2779,  2780,  2781,  2782,
    2784,  2785,  2787,  2788,  2789,  2790,  2791,  2792,  2793,  2794,
    2795,  2796,  2797,  2798,  2800,  2802,  2803,  2804,  2805,  2806,
    2807,  2808,  2809,  2810,  2811,  2813,  2814,  2815,  2816,  2817,
    2818,  2819,  2820,  2822,  2824,  2825,  2827,  2829,  2830,  2831,
    2832,  2833,  2834,  2835,  2836,  2837,  2838,  2839,  2840,  2841,
    2842,  2843,  2844,  2846,  2848,  2849,  2851,  2853,  2855,  2856,
    2857,  2858,  2859,  2860,  2862,  2863,  2864,  2865,  2866,  2867,
    2869,  2871,  2872,  2874,  2875,  2876,  2878,  2879,  2881,  2883,
    2885,  2886,  2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,
    2895,  2897,  2898,  2899,  2900,  2901,  2902,  2903,  2904,  2906,
    2907,  2908,  2909,  2911,  2912,  2913,  2916,  2917,  2918,  2920,
    2923,  2924,  2925,  2928,  2939,  2951,  2958,  2965,  2972,  2979,
    2986,  3033,  3040,  3047,  3054,  3061,  3068,  3077,  3085,  3095,
    3102,  3113,  3128,  3144,  3152,  3162,  3170,  3180
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LIST", "NAME", "FUNCTION", "STRING",
  "INTNUM", "BOOL", "APPROXNUM", "USERVAR", "ASSIGN", "OR", "XOR", "ANDOP",
  "REGEXP", "LIKE", "IS", "IN", "'!'", "NOT", "BETWEEN", "COMPARISON",
  "'|'", "'&'", "SHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "MOD", "'^'",
  "UMINUS", "ACCESSIBLE", "ADD_SQL", "ALL", "ALTER", "ANALYZE", "AND",
  "ANY", "AS", "ASENSITIVE", "ASC", "BEFORE", "BIGINT", "BINARY", "BIT",
  "BLOB", "BOTH", "BY", "CALL", "CASCADE", "CASE", "CHANGE", "CHAR",
  "CHECK", "COLLATE", "COLUMN", "CONDITION", "CONSTRAINT", "CONTINUE",
  "CONVERT", "CREATE", "CROSS", "CURRENT_DATE", "CURRENT_TIME",
  "CURRENT_TIMESTAMP", "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES",
  "DAY_HOUR", "DAY_MICROSECOND", "DAY_MINUTE", "DAY_SECOND", "DECIMAL",
  "DECLARE", "DEFAULT", "DELAYED", "DELETE_SQL", "DESC", "DETERMINISTIC",
  "DISTINCT", "DISTINCTROW", "DIV", "DOUBLE", "DROP", "DUAL", "EACH",
  "ELSE", "ELSEIF", "ENCLOSED", "ENUM", "ESCAPED", "EXISTS", "EXIT",
  "EXPLAIN", "FALSE", "FETCH", "FLOAT", "FOR", "FORCE", "FOREIGN", "FROM",
  "FULLTEXT", "GRANT", "GROUP", "HAVING", "HIGH_PRIORITY",
  "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF", "IGNORE",
  "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE", "INSERT", "INT",
  "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY", "KEYS", "KILL",
  "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LINER", "LOAD",
  "LOCALTIME", "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT",
  "LOOP", "LOW_PRIORITY", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODE", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMERIC", "ON", "ONDUPLICATE",
  "OPTIMIZE", "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE",
  "PRECISION", "PRIMARY", "PROCEDURE", "PURGE", "READ", "READS", "REAL",
  "REFERENCES", "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE",
  "RESTRICT", "RETURN", "REVOKE", "RIGHT", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET",
  "SETNAMES", "SETCHARACTER", "SETTRAN", "SETPASSWORD", "SETOPTION",
  "SHARE", "SHOW", "SHOWVARIABLES", "SHOWCOLLATION", "SMALLINT", "SPATIAL",
  "SPECIFIC", "SQL", "SQLEXCEPTION", "SQLSTATE", "SQLWARNING",
  "SQL_BIG_RESULT", "SQL_CALC_FOUND_ROWS", "SQL_SMALL_RESULT", "SSL",
  "STARTING", "STRAIGHT_JOIN", "TABLE", "TRUE", "TERMINATED", "THEN",
  "TINYBLOB", "TINYINT", "TINYTEXT", "TRUNCATE", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "X509", "YEAR_MONTH", "ZEROFILL", "FSTART", "FABS",
  "FACOS", "FADDTIME", "FAES_DECRYPT", "FAES_ENCRYPT", "FAREA",
  "FASBINARY", "FASIN", "FASTEXT", "FASWKB", "FASWKT", "FATAN", "FATAN2",
  "FASCII", "FAVG", "FADDDATE", "FBENCHMARK", "FBIN", "FBIT_AND",
  "FBIT_OR", "FBIT_XOR", "FBIT_COUNT", "FBIT_LENGTH", "FCAST", "FCEILING",
  "FCENTROID", "FCHAR", "FCHARACTER_LENGTH", "FCOERCIBILITY", "FCOMPRESS",
  "FCONCAT", "FCONCAT_WS", "FCONNECTION_ID", "FCONV", "FCONVERT_TZ",
  "FCOS", "FCOT", "FCRC32", "FCROSSESS", "FCOUNT", "FCHARSET",
  "FCOLLATION", "FCURRENT_USER", "FCURDATE", "FCURRENT_DATE", "FCURTIME",
  "FCURTIME_TIME", "FCURRENT_TIMESTAMP", "FDATE", "FDATEDIFF", "FDATENAME",
  "FDATEOFMONTH", "FDATEOFWEEK", "FDATEOFYEAR", "FDATE_ADD", "FDATE_SUB",
  "FDATE_FORMAT", "FDATABASE", "FDAY", "FDAYNAME", "FDAYOFMONTH",
  "FDAYOFWEEK", "FDAYOFYEAR", "FDEFAULT", "FDECODE", "FDEGREES",
  "FDES_DECRYPT", "FDES_ENCRYPT", "FDIMENSION", "FISJOINT", "FELT",
  "FENCODE", "FENCRYPT", "FENDPOINT", "FENVELOPE", "FEQUALS", "FEXP",
  "FEXPORT_SET", "FEXTRACT", "FEXTERIORRING", "FEXTRACTVALUE", "FFIELD",
  "FFIND_IN_SET", "FFLOOR", "FFORMAT", "FFOUND_ROWS", "FFROM_DAYS",
  "FFROM_UNIXTIME", "FGET_FORMAT", "FGEOMCOLLFROMTEXT", "FGEOMCOLLFROMWKB",
  "FGEOMETRYCOLLECTIONFROMTEXT", "FGEOMETRYCOLLECTIONFROMWKB",
  "FGEOMETRYFROMTEXT", "FGEOMETRYFROMWKB", "FGEOMETRYN", "FGEOMETRYTYPE",
  "FGEOMFROMTEXT", "FGEOMFROMWKB", "FGET_LOCK", "FGLENGTH", "FGREATEST",
  "FHEX", "FHOUR", "FINSERT", "FINSTR", "FIFNULL", "FIF", "FINET_ATON",
  "FINET_NTOA", "FINTERIORRINGN", "FINTERSECTS", "FISCLOSED", "FISEMPTY",
  "FISNULL", "FISSIMPLE", "FIS_FREE_LOCK", "FIS_USED_LOCK", "FLAST_DAY",
  "FLAST_INSERT_ID", "FLCASE", "FLEFT", "FLENGTH", "FLINEFROMTEXT",
  "FLINEFROMWKB", "FLINESTRINGFROMTEXT", "FLINESTRINGFROMWKB", "FLN",
  "FLOAD_FILE", "FLOCATE", "FLOG", "FLOG10", "FLOG2", "FLOWER", "FLPAD",
  "FLTRIM", "FLOCALTIME", "FLOCALTIMESTAMP", "FMAKEDATE", "FMAKETIME",
  "FMAKE_SET", "FMASTER_POS_WAIT", "FMBRCONTAINS", "FMBRDISJOINT",
  "FMBREQUAL", "FMBRINTERSECTS", "FMBROVERLAPS", "FMBRTOUCHES",
  "FMBRWITHIN", "FMD5", "FMLINEFROMTEXT", "FMLINEFROMWKB", "FMONTHNAME",
  "FMPOINTFROMTEXT", "FMPOINTFROMWKB", "FMPOLYFROMTEXT", "FMPOLYFROMWKB",
  "FMULTILINESTRINGFROMTEXT", "FMULTILINESTRINGFROMWKB",
  "FMULTIPOINTFROMTEXT", "FMULTIPOINTFROMWKB", "FMULTIPOLYGONFROMTEXT",
  "FMULTIPOLYGONFROMWKB", "FMICROSECOND", "FMINUTE", "FMONTH",
  "FGROUP_CONCAT", "FAGAINST", "FMATCH", "FMAX", "FMID", "FMIN", "FMOD",
  "FNOW", "FNAME_CONST", "FNULLIF", "FNUMGEOMETRIES", "FNUMINTERIORRINGS",
  "FNUMPOINTS", "FOCT", "FOCTET_LENGTH", "FORD", "FOVERLAPS",
  "FOLD_PASSWORD", "FPERIOD_ADD", "FPERIOD_DIFF", "FPI", "FPOSITION",
  "FPASSWORD", "FPOINTFROMTEXT", "FPOINTFROMWKB", "FPOINTN",
  "FPOLYFROMTEXT", "FPOLYFROMWKB", "FPOLYGONFROMTEXT", "FPOLYGONFROMWKB",
  "FPOWER", "FQUARTER", "FQUOTE", "FRADIANS", "FRAND", "FROUND",
  "FROW_COUNT", "FREPEAT", "FREPLACE", "FREVERSE", "FRIGHT", "FRPAD",
  "FRTRIM", "FRELEASE_LOCK", "FSEC_TO_TIME", "FSEC_TO_DATE", "FSHA",
  "FSHA1", "FSLEEP", "FSCHEMA", "FSOUNDEX", "FSPACE", "FSQRT", "FSRID",
  "FSTARTPOINT", "FSTRCMP", "FSTR_TO_DATE", "FSECOND", "FSUBTIME", "FSIGN",
  "FSIN", "FSUBSTRING", "FSUBSTRING_INDEX", "FSESSION_USER", "FSTD",
  "FSTDDEV", "FSTDDEV_POP", "FSTDDEV_SAMP", "FSUBDATE", "FSUM", "FSYSDATE",
  "FSYSTEM_USER", "FTAN", "FTIMEDIFF", "FTIME_FORMAT", "FTIME_TO_SEC",
  "FTRUNCATE", "FTOUCHES", "FTO_DAYS", "FTRIM", "FTIME", "FTIMESTAMP",
  "FTIMESTAMPADD", "FTIMESTAMPDIFF", "FVARIANCE", "FVAR_POP", "FVAR_SAMP",
  "FUCASE", "FUNCOMPRESS", "FUNCOMPRESSED_LENGTH", "FUNHEX", "FUSER",
  "FUNIX_TIMESTAMP", "FUPDATEXML", "FUPPER", "FUUID", "FUUID_SHORT",
  "FVERSION", "FUTC_DATE", "FUTC_TIME", "FUTC_TIMESTAMP", "FWEEK",
  "FWEEKDAY", "FWEEKOFYEAR", "FYEAR", "FYEARWEEK", "FX", "FY", "FEND",
  "SUB_OP", "ADD_OP", "MUL_OP", "DIV_OP", "BITOR_OP", "BITXOR_OP",
  "BITAND_OP", "';'", "','", "'.'", "'('", "')'", "$accept", "stmt_list",
  "stmt", "select_reduce_stmt", "select_stmt", "opt_where", "opt_groupby",
  "groupby_list", "opt_asc_desc", "opt_with_rollup", "opt_having",
  "opt_orderby", "orderby_list", "opt_limit", "opt_into_list",
  "column_list", "select_opts", "select_expr_list", "select_expr",
  "table_references", "table_reference", "table_factor", "opt_as",
  "opt_as_alias", "join_table", "opt_inner_cross", "opt_outer",
  "left_or_right", "opt_left_or_right_outer", "opt_join_condition",
  "reduce_using", "join_condition", "index_hint", "opt_for_join",
  "index_list", "table_subquery", "delete_reduce_stmt", "delete_stmt",
  "delete_opts", "delete_list", "opt_dot_star", "insert_reduce_stmt",
  "insert_value_reduce_stmt", "insert_stmt", "opt_ondupupdate",
  "insert_opts", "opt_into", "opt_col_names", "insert_vals_list",
  "insert_vals", "insert_asgn_list", "replace_reduce_stmt",
  "replace_value_reduce_stmt", "replace_stmt", "update_reduce_stmt",
  "update_stmt", "update_opts", "expr_or_null_default", "update_asgn_list",
  "create_database_stmt", "opt_if_not_exists", "create_table_stmt",
  "create_col_list", "create_definition", "$@1", "column_atts",
  "opt_length", "opt_binary", "opt_uz", "opt_csc", "data_type",
  "enum_list", "create_select_statement", "opt_ignore_replace",
  "opt_temporary", "show_reduce_stmt", "show_stmt", "set_opt", "use_stmt",
  "truncate_stmt", "desc_stmt", "set_reduce_stmt", "name_or_default",
  "set_stmt", "set_list", "set_password_opt", "set_opt_expr", "set_expr",
  "expr", "val_list", "opt_val_list", "trim_ltb", "interval_exp",
  "case_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    33,
     274,   275,   276,   124,    38,   277,    43,    45,    42,    47,
      37,   278,    94,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   753,   754,   755,
     756,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   773,   774,    59,
      44,    46,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   534,   535,   535,   535,   536,   537,   538,   538,   539,
     539,   540,   540,   541,   541,   542,   542,   542,   543,   543,
     544,   544,   545,   545,   546,   546,   547,   547,   547,   548,
     548,   549,   549,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   551,   551,   551,   552,   552,   552,   553,   553,
     554,   554,   555,   555,   555,   555,   556,   556,   557,   557,
     558,   558,   558,   558,   558,   559,   559,   559,   560,   560,
     561,   561,   562,   562,   562,   563,   563,   564,   565,   565,
     566,   566,   566,   566,   566,   566,   566,   567,   567,   568,
     568,   568,   569,   536,   570,   571,   571,   572,   572,   572,
     571,   573,   573,   574,   574,   571,   536,   575,   576,   577,
     577,   578,   578,   579,   579,   579,   579,   579,   580,   580,
     581,   581,   582,   582,   583,   583,   577,   577,   577,   577,
     584,   536,   585,   586,   587,   587,   587,   587,   587,   587,
     536,   588,   589,   590,   590,   590,   591,   591,   591,   592,
     592,   592,   592,   536,   593,   593,   594,   594,   536,   595,
     595,   595,   595,   595,   595,   596,   596,   598,   597,   597,
     597,   597,   597,   597,   599,   599,   599,   599,   599,   599,
     599,   599,   599,   599,   599,   599,   599,   600,   600,   600,
     601,   601,   602,   602,   602,   603,   603,   603,   604,   604,
     604,   604,   604,   604,   604,   604,   604,   604,   604,   604,
     604,   604,   604,   604,   604,   604,   604,   604,   604,   604,
     604,   604,   605,   605,   606,   607,   607,   607,   608,   608,
     536,   609,   609,   610,   610,   610,   611,   611,   611,   611,
     536,   612,   536,   613,   613,   536,   614,   614,   536,   615,
     616,   616,   616,   617,   617,   617,   617,   617,   617,   618,
     618,   619,   619,   620,   620,   620,   620,   621,   621,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   623,   623,
     624,   624,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     625,   625,   625,   622,   622,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   622,   622,   622,
     622,   627,   627,   622,   622,   622,   622,   622
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     1,     3,    11,     0,
       2,     0,     4,     2,     4,     0,     1,     1,     0,     2,
       0,     2,     0,     3,     2,     4,     0,     2,     4,     0,
       2,     1,     3,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     2,     3,     3,     1,     3,
       1,     1,     3,     5,     3,     3,     1,     0,     2,     0,
       5,     3,     5,     6,     5,     0,     1,     1,     0,     1,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     4,
       6,     6,     6,     6,     6,     6,     0,     2,     0,     1,
       1,     3,     3,     1,     1,     7,     9,     2,     2,     0,
       6,     2,     4,     0,     2,     7,     1,     1,     1,     8,
      10,     0,     4,     0,     2,     2,     2,     2,     1,     0,
       0,     3,     3,     5,     1,     3,     7,     9,     7,     9,
       1,     1,     1,     1,     8,    10,     7,     9,     7,     9,
       1,     1,     8,     0,     2,     2,     1,     1,     1,     3,
       5,     5,     7,     1,     4,     4,     0,     2,     1,     8,
      10,     9,     6,    11,     8,     1,     3,     0,     4,     5,
       4,     4,     5,     5,     0,     3,     2,     3,     3,     3,
       3,     2,     5,     3,     3,     2,     3,     0,     3,     5,
       0,     1,     0,     2,     2,     0,     4,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     2,     4,     1,     1,     1,     1,     3,     3,     3,
       5,     5,     1,     3,     3,     0,     1,     1,     0,     1,
       1,     1,     1,     2,     3,     3,     2,     1,     1,     2,
       1,     2,     1,     2,     4,     1,     2,     4,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       5,     6,     6,     6,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     4,     3,     3,     4,     5,     1,     3,
       0,     1,     5,     6,     5,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     4,     4,     4,     4,     4,     4,     5,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     4,     4,     5,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     3,
       4,     4,     4,     3,     4,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     6,     8,     7,     4,
       1,     1,     1,     6,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     6,     3,
       5,     4,     5,     3,     4,     3,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     2,   228,    94,     0,   107,   132,     6,   249,     0,
       0,   258,   262,   257,   231,   232,     0,   141,     0,     0,
       0,    33,     5,    99,    93,   113,   106,   113,   131,   113,
     140,   153,   158,     9,   230,   240,   242,   245,     0,   248,
     229,   156,   156,     0,   246,   250,   251,   252,   254,     0,
       0,     0,   243,   241,     1,     0,     3,     0,     0,   119,
     119,     0,     0,     0,     0,   233,   237,   238,     0,   253,
     259,     0,     0,     0,   156,     0,   256,   261,     0,     0,
       4,   269,   272,   273,   275,   274,   270,     0,     0,     0,
      44,    34,     0,     0,   148,    35,    36,     0,    37,     0,
     146,    40,    41,    39,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,    42,    59,   147,     0,   103,     0,    98,    97,     0,
     115,   116,   117,   118,   114,     0,     0,   117,   114,    59,
       0,     0,    48,    50,    51,    57,   235,   234,   269,    10,
     236,   239,     0,     0,     0,   157,   154,   155,     0,   247,
     255,   244,     0,     0,     0,   299,   298,   285,   627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     9,     0,     0,
       0,   120,   120,     0,    86,     0,     0,     0,     0,    67,
      66,    70,    74,    71,     0,     0,    68,     0,     0,   310,
     268,   264,   266,   265,   267,   263,   260,   225,   271,    46,
      47,   308,   311,     0,   300,     0,     0,   619,     0,     0,
       0,   610,   605,   606,   607,   608,   611,   612,   613,   615,
     616,   614,   609,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   363,   364,
     365,   367,   368,   366,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   519,     0,     0,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,   549,     0,
       0,     0,     0,     0,     0,     0,   557,   558,     0,     0,
       0,     0,     0,     0,     0,   602,   600,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   578,   579,     0,     0,     0,   583,     0,   585,   586,
     587,   588,     0,     0,     0,     0,     0,     0,     0,   301,
       9,    43,    58,   287,   288,   286,   625,   623,   305,     0,
     302,     0,     0,     0,     0,     0,   269,     0,     0,   304,
       0,   289,   294,   295,   297,   276,   277,   280,   278,   281,
     282,   283,   284,   296,   279,   104,     0,    22,     0,     9,
     103,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    52,    92,    55,     0,     9,    49,    68,    68,
       0,    61,     0,    69,     0,    54,   226,   227,     0,   167,
     162,    57,     0,   317,     0,   617,     0,     0,     0,   316,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,     0,   332,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   352,   353,   354,   355,   356,   357,   359,
       0,   360,   361,   362,   369,   370,   371,   372,   373,   374,
       0,     0,   375,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   599,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     520,   521,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   536,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   534,   535,     0,   547,   548,   550,   551,
     552,   553,   554,     0,   555,   559,   560,   561,   562,   563,
     564,   565,   566,     0,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   580,   581,   582,   584,   589,
     590,   591,   592,   593,   594,   595,    11,   306,   303,     0,
       0,   626,   624,     0,     0,   310,     0,     0,     0,     9,
       0,    26,     9,   100,   102,   111,   130,   120,    31,     0,
     108,   111,     0,   111,   120,   133,   111,     0,    86,    88,
      88,    88,    88,    88,    88,     0,     0,     0,    22,    72,
      73,     0,     0,    76,     0,   225,     0,     0,     0,     0,
       0,   165,     0,     0,   309,   621,     0,   620,     0,   333,
     358,     0,     0,     0,   556,     0,     0,    20,   314,   312,
       0,     0,   307,     0,     0,     0,   290,    22,     0,     0,
      95,   105,     0,   126,     0,     0,     0,   121,   128,     0,
     111,   136,     0,     0,   138,   111,    53,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,    26,    64,    62,
       0,    77,    60,     0,    75,     0,   167,   164,     0,     0,
       0,     0,     0,   167,   225,     0,   224,   618,   622,   603,
     604,     0,   596,     0,     0,     0,    22,   315,   313,   292,
     293,   291,    26,    23,    15,    27,     0,   111,   111,     0,
      32,     0,   124,     0,   109,   111,   111,     0,   134,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
      78,     0,    63,     0,     0,     0,     0,     0,     0,   166,
     161,   187,   187,   187,   214,   187,   187,   187,     0,   187,
     187,   187,   216,   190,   215,   187,   190,   187,     0,   187,
     213,   187,   190,     0,     0,   174,     0,   598,    18,    15,
      21,    26,    96,     0,    16,    17,    24,     0,     0,   127,
     129,   111,     0,   122,     0,   137,   139,   111,    89,    90,
       0,     0,     0,     0,     0,     0,   150,   151,     0,     0,
     225,     0,     0,   171,   170,     0,     0,   198,   192,   211,
     195,   192,   192,     0,   192,   192,   192,   191,   195,   192,
     195,   192,     0,   192,   192,   195,     0,     0,   168,   597,
       0,     0,    12,    13,    29,    15,    28,   112,   110,   125,
       0,   135,     0,    85,    82,    84,    81,    83,    80,     0,
      79,   163,   172,   173,   169,     0,   204,   209,   208,   206,
     222,     0,   207,   202,   203,   219,   201,   218,   205,     0,
     200,   199,   217,     0,     0,   181,     0,     0,   185,   176,
       0,     0,    19,    15,     0,     8,    25,   123,    91,   152,
       0,   188,   193,   194,     0,     0,     0,   195,   195,   212,
     195,   186,   175,   177,   178,   180,   179,   184,   183,     0,
      14,    30,     0,     0,   197,   223,   220,   221,   210,     0,
     189,   196,   182
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    65,  1487,  1628,  1636,  1692,
    1556,  1431,  1563,  1500,  1745,  1439,    57,   380,   381,   401,
     402,   403,   712,   713,   404,   755,  1144,   756,  1140,  1532,
    1533,  1534,  1132,  1518,  1650,   405,    23,    24,    58,   389,
     736,    25,  1442,    26,  1503,    59,   395,  1124,  1510,  1571,
    1435,    27,  1447,    28,    29,    30,    62,   382,  1136,    31,
      72,    32,  1470,  1471,  1472,  1688,  1667,  1678,  1716,  1717,
    1625,  1721,  1150,  1151,    43,    33,    34,    68,    35,    36,
      37,    38,    48,    39,  1436,    51,   764,    70,   771,   772,
     773,  1049,   384,   431
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1334
static const yytype_int16 yypact[] =
{
     871, -1334,   349, -1334,    25, -1334, -1334, -1334, -1334,   409,
    -150, -1334,   -67, -1334, -1334, -1334,    98, -1334,   126,   778,
    -348, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,     2,
   -1334, -1334, -1334,    72, -1334, -1334, -1334, -1334,   378, -1334,
   -1334,   169,   169,   225,   -65, -1334, -1334, -1334, -1334,   409,
     362,   513,    15, -1334, -1334,    37, -1334,  3476,   719,   752,
     752,   271,     4,   400,  9163, -1334,   404, -1334,    78,    45,
   -1334,   551,   659,   676,   169,   690, -1334, -1334,  9163,   693,
   -1334,  -507, -1334, -1334, -1334, -1334,   674,  9163,  9163,  9163,
   -1334, -1334,  9163,  7095, -1334, -1334, -1334,   176, -1334,  9163,
   -1334, -1334, -1334, -1334, -1334,   195,   207,   233,   247,   248,
     249,   260,   284,   293,   297,   303,   317,   318,   323,   324,
     325,   330,   332,   333,   336,   338,   339,   341,   342,   343,
     345,   346,   347,   348,   350,   358,   360,   363,   365,   374,
     383,   384,   385,   387,   388,   391,   394,   403,   408,   410,
     421,   424,   428,   429,   430,   432,   440,   441,   444,   445,
     446,   449,   453,   454,   455,   457,   458,   461,   462,   463,
     465,   466,   467,   472,   474,   478,   482,   483,   487,   491,
     493,   497,   498,   499,   500,   501,   505,   506,   507,   508,
     509,   510,   512,   514,   526,   533,   534,   537,   538,   540,
     541,   555,   558,   559,   560,   562,   563,   569,   570,   571,
     572,   573,   575,   576,   577,   578,   579,   580,   581,   591,
     605,   606,   607,   608,   609,   618,   639,   660,   695,   696,
     697,   699,   701,   702,   704,   713,   739,   740,   741,   742,
     744,   753,   800,   801,   802,   803,   804,   805,   807,   808,
     809,   811,   812,   820,   843,   867,   868,   869,   870,   872,
     874,   875,   876,   877,   878,   879,   881,   887,   888,   890,
     891,   892,   893,   894,   897,   898,   899,   900,   901,   902,
     904,   905,   906,   907,   908,   911,   912,   913,   914,   915,
     916,   917,   919,   921,   923,   924,   925,   926,   927,   928,
     930,   931,   932,   933,   934,   935,   955,   956,   957,   958,
     959,   960,   961,   963,   964,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,  1004,  1018,  1019,
    1020,  1021,  1022,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,  1042,  1043,  1045,  1046,  1047,  1049,  1050,  1051,  1052,
    1054,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  9163,
      -5, -1334,   355,  1356,   861,   376,   954, -1334, -1334,   156,
   -1334, -1334, -1334, -1334, -1334,   975,  1084,     5,     6,    36,
      33,  -165,   700, -1334, -1334,   853, -1334, -1334,  -440,  1356,
   -1334, -1334,  9163,  5027,   378, -1334, -1334, -1334,  1089, -1334,
    1356, -1334,   371,  1408,  9163,  1278,  1278, -1334, -1334,  9163,
    1104,   270,   751,   773,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  7612,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,   680,  9163,  9163,  9163,
    9163,  9163,  9163,  5544,  9163,  9163,  1074,  1075,  1076,  1077,
    1078,  1079,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  1080,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  1081,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  1925,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    1082,  1083,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  1085,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    1086,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  2442,  9163,  1087,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  1088,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  1090,  9163,  9163,  9163,  9163,  9163,  8129,
    1091,  1092,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  3993,
    9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  1093,  2959,  9163,  9163,  1094,  9163,  1095,  1096,  1097,
    1098,  9163,  9163,  9163,  9163,  9163,  9163,  9163,   426,     4,
    6061, -1334,  1228, -1334,  9163,  9163,  9163,  9163,  9163,   375,
    1100,   694,  9163,  4510,  9163,  9163,  9163,  9163,  9163,  9163,
    9163,  9163,  9163,  9163,  9163,   972, -1334,   118,  -210,     4,
    1231,  -170,  -162,  1399,   295,  1102,  -146,  1446,     4, -1334,
   -1334, -1334,   -91, -1334,     4,   945,   882,  1551,  1602,  9163,
    1356,  9163, -1334, -1334, -1334,  1356, -1334,   188, -1334, -1334,
   -1334,   556, -1334,  1103,  1356,  1131,   528, -1334,  9163,  9163,
    1105, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1120,  9163,  1121,  1397,
    1403,  1404,  1405,  1406,  1409,  1410,  1413,  1414,  1415,  1416,
    1417,  1418,  1420,  1421,  1422,  1423, -1334,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  9163,   447,  1431,  1432, -1334, -1334,
   -1334, -1334, -1334, -1334,  1433,  1434,  1435,  1436,  1437,  1439,
     585,   612,  1440, -1334,  1441,  1442,  1443,  1444,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,
    1470, -1334,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1485,  1486,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505, -1334,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1516,  1518,  1519,  1520,  1521,
    1522,  1523,  1524, -1334, -1334,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,
    1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,
    1550,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,
   -1334,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1572, -1334,   468,  1573,  1574,  1575,  1576,  1577,
    1578,  1579,  1580,  1581,  1582,  1583,  1584, -1334,  1585,  1586,
   -1334,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598, -1334,  1599,  1600,  1601,  1603,  1604,  1605,
    1606,  1607,  1608,  1609,  1610,   527,  1611,  1612, -1334,  1613,
    1614,  1615,  1616,  1617,  9163,  1618, -1334, -1334,  1619,  1620,
    1621,  1622,  1623,  1624,  1625, -1334, -1334, -1334,  1626,  9163,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,
    1637, -1334, -1334,  1638,  1914,  1920, -1334,  1921, -1334, -1334,
   -1334, -1334,  1922,  1923,  1926,  1927,  1930,  1931,  1932, -1334,
    -211, -1334, -1334,  1333,  1454,  1484,  1517,  1517, -1334,   224,
   -1334,  8646,  9163,  9163,  1101,  1299,    30,  1934,  1935, -1334,
    8646,  1237,  1365,  1023,   918,   561, -1334,   561, -1334,  1947,
    1947,  1947,  1947, -1334,   561, -1334,   373,  1826,     4,  -211,
     376,   378,  2013,  2046,   164,   378,  2080,   173,   355,   264,
     302,   308, -1334, -1334, -1334,    -9,  -200,   700,   882,   882,
    2009,  2312,     4, -1334,  2344, -1334, -1334, -1334,  2467,   703,
   -1334,   853,  9163, -1334,  9163, -1334,  9163,  1226,  1152, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334,  1939, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
    1940, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
    2351,  2351, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,  9163, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  1942, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  1173, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,  1515, -1334, -1334,  1943,
    1944,  1517,  1517,  8646,  9163,  8646,   751,   751,  1945,  1378,
    2429,  2347,  -211, -1334, -1334,  2324,    45,  -169, -1334,  -144,
   -1334,  2324,  1950,  2324,  -161, -1334,  2324,  1950,   295,  2382,
    2382,  2382,  2382,  2382,  2382,  6578,  2480,  2481,  1826, -1334,
   -1334,     4,  9163,   190,     4,   192,   564,  1954,  1955,  2362,
    -100, -1334,  2486,   751, -1334,  1356,  1266, -1334,  9163, -1334,
   -1334,  1958,  1959,   311, -1334,  9163,  2443,  2386, -1334, -1334,
    1963,  1964,  1053,  1965,  1966,  1967, -1334,  1826,  9163,  9163,
   -1334, -1334,  2374, -1334,   378,   164,  2498, -1334, -1334,  6578,
    -140, -1334,   378,   173, -1334,  -140, -1334,  2377,  1972,  1973,
    1974,  1975,  1976,  1977, -1334,  2488,    -8,  2347, -1334,  1356,
    9163, -1334, -1334,  1979, -1334,   190,   703, -1334,  1980,  1981,
    2046,  2046,  1982,   703,   -92,   767, -1334, -1334,  1356, -1334,
   -1334,  9163, -1334,  1983,  9163,  9163,  1826, -1334, -1334, -1334,
   -1334, -1334,  2347,  1985,  1194,   729,  2290,  2324,  2324,  1950,
   -1334,     0, -1334,  1986, -1334,  2324,  2324,  1950, -1334, -1334,
     178,   178,   178,   178,   178,   178,  6578,  6578,  2515, -1334,
    1356,  2046, -1334,   117,  2046,  2046,   122,   151,  2046, -1334,
   -1334,  1988,  1988,  1988, -1334,  1988,  1988,  1988,  1989,  1988,
    1988,  1988, -1334,  2476, -1334,  1988,  2476,  1988,  1991,  1988,
   -1334,  1988,  2476,  1992,  1993, -1334,   489, -1334,  -154,  1194,
    1356,  2347, -1334,  9163, -1334, -1334, -1334,  9163,   378, -1334,
   -1334,  -140,  6578, -1334,  6578, -1334, -1334,  -140, -1334, -1334,
     166,   183,   185,   196,   201,   205, -1334, -1334,  2504,   239,
     133,   240,   276, -1334, -1334,   277,  2520, -1334, -1334, -1334,
   -1334, -1334, -1334,  2522, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,  2522, -1334, -1334, -1334,  2523,  2524,   764, -1334,
    2525,  9163, -1334, -1334,  2408,  1194,  1356, -1334, -1334, -1334,
     281, -1334,  2529, -1334, -1334, -1334, -1334, -1334, -1334,  6578,
   -1334, -1334, -1334, -1334, -1334,   291,   155,   539,   155,   155,
   -1334,   304,   155,   155,   155,   539,   155,   539,   155,   306,
     155,   155,   539,  2001,  2002,  2530,  2384,   681, -1334, -1334,
    2412,  -111, -1334,  1194,  2046, -1334, -1334, -1334, -1334, -1334,
    2533, -1334, -1334, -1334,  2353,  2536,  2537, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,  2046,
   -1334,  2014,  2012,  2540, -1334, -1334,   539,   539,   539,   321,
   -1334, -1334, -1334
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1334, -1334,  2528, -1334,  -399,  -726, -1334, -1334, -1321, -1334,
   -1334,  -780, -1334,  -967, -1334,  -858, -1334, -1334,  1838,  -388,
     889,  -750,  -403,  -396, -1334, -1334,  -364, -1334, -1334, -1334,
   -1334,  1014,  1119,  -831,  -681, -1334, -1334, -1334, -1334,  2164,
    1438, -1334,  1048, -1334,  -748,   627,  2491,  -737, -1166,   910,
   -1110, -1334,  1044, -1334, -1334, -1334, -1334,  -804, -1334, -1334,
     331, -1334,  1016,  1012, -1334, -1334,  -678, -1188,  -663, -1333,
   -1334,   880, -1234, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,  2507, -1334,  2521, -1334, -1334,  2146,   -57,  -389,
   -1334, -1334,  -684,  2131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -161
static const yytype_int16 yytable[] =
{
     383,   745,   757,   744,  1141,  1127,  -143,   409,   399,  -145,
    -144,  1117,   746,  1455,  1587,  1443,  1768,  1502,  1121,  1504,
    1118,   420,  1146,   747,   422,   423,  1125,  1512,    64,    44,
     425,   426,   427,   780,    50,   428,   430,   399,    49,    64,
     -57,  1138,   433,  1106,  1108,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   808,
     809,   810,   811,   812,   813,   814,   815,   816,   817,   818,
     819,   820,   821,   822,   823,   824,   825,   711,   827,   828,
     829,   830,   831,   832,  1147,   836,   837,  1690,    63,   412,
    1139,   758,   759,   844,   845,   846,   847,   848,   849,   709,
     413,   852,    52,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
      53,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,   904,   905,   906,   907,   908,   909,   910,
     911,   912,   913,   914,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,    56,  1648,   935,   936,   937,   938,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,   969,     7,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,  1537,  1417,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   998,   999,  1146,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,
     739,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1026,  1027,   777,  1029,  1030,  1031,  1032,  1033,
    1035,  1515,    71,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1048,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1146,  1063,  1064,  1065,  1146,  1067,  1693,  1147,
    1600,    64,  1072,  1073,  1074,  1075,  1076,  1077,  1078,   748,
     740,  1080,   708,   714,   715,   716,   717,   718,   719,   720,
    1457,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,  1649,  1725,  1530,  1727,  -103,     7,
     390,  1119,  1732,    40,  1416,   760,   765,    64,     7,   -57,
     778,  1122,  1123,  1123,  1147,   748,    77,   774,  1147,  1126,
    1123,  1123,   775,    73,  1746,   768,  1691,  1429,  1418,  1449,
     391,  1752,    66,  1088,   748,   397,  1506,  1134,    67,  1507,
    1573,  1450,  1463,  1433,  1567,  1089,   711,  1129,  1440,   769,
    1753,  1115,  1575,  1641,   406,   418,   407,  1445,   410,  1130,
    1458,  1647,  1551,    45,   411,   398,   835,  1451,  1174,    41,
    1531,  1769,  1770,  1453,  1776,  1777,  1711,  1778,  1680,  1452,
    1543,   850,   851,  1544,  1685,  1454,    74,  -159,   714,   715,
     716,   717,   718,   719,   720,  1200,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   714,
     715,   716,   717,   718,   719,   720,    75,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     714,   715,   716,   717,   718,   719,   720,    46,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   714,   715,   716,   717,   718,   719,   720,   779,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,  1456,  1588,  1131,   710,  1481,  1482,  1697,  1090,
    1642,    42,  1155,  1643,  -143,    78,   400,  -145,  -144,   714,
     715,   716,   717,   718,   719,   720,    79,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
    1589,   758,  1425,    47,   984,   400,    80,   743,   714,   715,
     716,   717,   718,   719,   720,   414,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   729,
     730,   731,   732,   733,  1754,  1632,  1755,   714,   715,   716,
     717,   718,   719,   720,  1025,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,  1156,  1519,
    1520,  1521,  1522,  1523,   714,   715,   716,   717,   718,   719,
     720,  1375,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,  1383,   415,  1543,  -103,  1116,
    1660,  1524,  1506,   383,    60,  1663,    61,  1083,  1084,  1085,
    1086,  1087,  -160,   416,  1694,  1095,  1101,  1102,  1103,  1104,
    1105,  1107,  1109,  1110,  1111,  1112,  1113,  1114,  1527,  1538,
     417,  1506,  1596,  1597,  1664,   424,   740,  1763,  1764,  1765,
    1766,  1539,  1419,  1508,   419,  1511,  1702,   421,  1514,  1703,
    1505,  1428,  1420,  1497,   428,  1572,  1501,  1513,   432,  1092,
    1093,  1528,  1094,  1702,  1535,  1702,  1704,  1562,  1705,  1148,
    1149,  1157,  1158,   385,  1536,  1441,  1702,   434,  1446,  1706,
    1432,  1702,  1448,  1659,  1707,  1702,  1661,  1662,  1708,   435,
    1665,   714,   715,   716,   717,   718,   719,   720,  1473,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,  1574,  1474,   749,   436,   779,  1578,  1735,  1506,
    1506,  1601,  1710,  1712,  1459,  1460,  1631,   781,    54,   437,
     438,   439,  1656,  1657,  1736,   714,   715,   716,   717,   718,
     719,   720,   440,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,  1506,  1506,  1466,  1713,
    1714,  1642,  1602,  1603,  1747,  1604,   441,   750,  1467,  1639,
    1640,  1750,  1605,   386,  1751,   442,   -65,  1645,  1646,   443,
    1468,   390,   751,   387,  1756,   444,  1756,  1757,  1699,  1758,
    1572,     2,  1737,  1606,  1552,   782,   783,   784,   785,   445,
     446,  1506,   752,  1607,  1782,   447,   448,   449,     3,     4,
    1608,   391,   450,   388,   451,   452,   392,  1609,   453,  1469,
     454,   455,     1,   456,   457,   458,   393,   459,   460,   461,
     462,   753,   463,   786,   787,   788,  1771,   734,  1610,  1611,
     464,  1738,   465,  1698,   711,   466,   394,   467,     5,  1701,
    1651,  1652,  1653,  1654,  1655,  1749,   468,   735,  1612,  1613,
     754,  1779,  1614,  1615,  1616,   469,   470,   471,  1739,   472,
     473,   789,   790,   474,  1668,  1669,   475,  1670,  1671,  1672,
    1740,  1674,  1675,  1676,     2,   476,     7,  1679,  1617,  1681,
     477,  1683,   478,  1684,   727,   728,   729,   730,   731,   732,
     733,     3,     4,   479,     6,  1618,   480,   791,   737,  1079,
     481,   482,   483,     7,   484,  1619,     8,     9,    10,    11,
      12,    13,   485,   486,    14,    15,   487,   488,   489,   741,
    1201,   490,  1620,  1621,  1622,   491,   492,   493,  1741,   494,
     495,     5,  1393,   496,   497,   498,    16,   499,   500,   501,
    1115,  1337,  1623,  1624,   502,    17,   503,    18,  1718,  1719,
     504,  1722,  1723,  1724,   505,   506,  1726,   792,  1728,   507,
    1730,  1731,  1689,   508,  1490,   509,  1493,  1494,  1495,   510,
     511,   512,   513,   514,  1491,  1421,  1422,   515,   516,   517,
     518,   519,   520,   708,   521,  1143,   522,     6,   726,   727,
     728,   729,   730,   731,   732,   733,     7,  1152,   523,     8,
       9,    10,    11,    12,    13,   524,   525,    14,    15,   526,
     527,  1142,   528,   529,  1546,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,  1152,   530,   742,    16,
     531,   532,   533,   767,   534,   535,  1553,  1475,    17,  1476,
      18,   536,   537,   538,   539,   540,  1568,   541,   542,   543,
     544,   545,   546,   547,  1576,  1210,   714,   715,   716,   717,
     718,   719,   720,   548,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   549,   550,   551,
     552,   553,  1211,   714,   715,   716,   717,   718,   719,   720,
     554,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   714,   715,   716,   717,   718,   719,
     720,   555,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   714,   715,   716,   717,   718,
     719,   720,   556,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   714,   715,   716,   717,
     718,   719,   720,   826,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   557,   558,   559,
    1477,   560,  1082,   561,   562,  1120,   563,  1634,   714,   715,
     716,   717,   718,   719,   720,   564,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,  1637,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
    1547,   565,   566,   567,   568,  1635,   569,  1485,   714,   715,
     716,   717,   718,   719,   720,   570,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   714,   715,   716,   717,   718,   719,   720,  1483,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   571,   572,   573,   574,   575,   576,  1424,   577,
     578,   579,   429,   580,   581,  1154,   715,   716,   717,   718,
     719,   720,   582,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,  1478,  1492,   714,   715,
     716,   717,   718,   719,   720,   583,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   383,   584,
     585,   586,   587,  1128,   588,  1529,   589,   590,   591,   592,
     593,   594,   408,   595,    82,    83,    84,    85,    86,   596,
     597,  1548,   598,   599,   600,   601,   602,    87,    88,   603,
     604,   605,   606,   607,   608,    89,   609,   610,   611,   612,
     613,  1564,  1565,   614,   615,   616,   617,   618,   619,   620,
    1135,   621,   383,   622,    92,   623,   624,   625,   626,   627,
     628,    93,   629,   630,   631,   632,   633,   634,   716,   717,
     718,   719,   720,  1590,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   635,   636,   637,
     638,   639,   640,   641,  1626,   642,   643,  1629,  1630,   717,
     718,   719,   720,    97,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   383,
     383,    99,  -161,  -161,  -161,  -161,   656,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     657,   658,   659,   660,   661,  1145,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,  1695,   682,   683,   684,
    1696,   685,   686,   687,   688,   383,   689,   383,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   768,   838,   839,   840,
     841,   842,   843,   853,   881,   933,   934,    64,   970,   983,
    1000,  1013,  1486,  1028,  1036,  1037,  1061,  1066,  1068,  1069,
    1070,  1071,  1091,  1423,  1743,  1133,  1153,  1137,  1159,  1160,
    1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,   383,  1173,  1175,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   408,
    1176,    82,    83,    84,    85,    86,  1177,  1178,  1179,  1180,
     379,   770,  1181,  1182,    87,    88,  1183,  1184,  1185,  1186,
    1187,  1188,    89,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,    92,  1209,  1212,  1213,  1214,  1215,  1216,    93,   733,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1430,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1437,  1253,  1254,
      97,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,    99,  1282,
    1438,  1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,
    1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,
    1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1314,  1315,  1444,  1316,  1317,  1318,  1319,  1320,
    1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,
    1331,  1332,  1333,  1334,  1335,  1336,  1338,  1339,  1340,  1341,
    1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  1366,  1461,  1367,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1376,  1377,  1378,  1379,  1380,  1381,
    1382,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,
    1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,
    1404,  1405,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   408,  1406,    82,    83,
      84,    85,    86,  1407,  1408,  1409,  1410,   379,   915,  1411,
    1412,    87,    88,  1413,  1414,  1415,  1426,  1427,  1462,    89,
    1464,  1465,  1479,  1480,    99,  1484,  1488,  1489,  1496,  1498,
    1499,  1502,  1509,  1517,  1525,  1526,  1540,  1541,    92,  1542,
    1545,  1549,  1550,  1554,  1555,    93,  1557,  1558,  1559,  1560,
    1561,  1566,  1570,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1586,  1591,  1594,  1595,  1598,  1633,  1627,  1638,  1644,  1658,
    1666,  1673,  1677,  1682,  1686,  1687,  1709,  1715,  1720,  1742,
    1733,  1734,  1744,  1748,  1759,  1760,  1761,    97,  1762,  1767,
    1772,  1773,  1774,  1775,  1506,  1780,  1781,    55,  1081,  1592,
     738,   396,  1593,  1569,  1700,  1599,    76,  1577,  1434,    69,
     766,   776,  1729,     0,     0,    99,     0,  1516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   408,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,   379,   997,     0,     0,    87,    88,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
      81,     0,    82,    83,    84,    85,    86,     0,     0,     0,
       0,   379,  1062,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,    89,    90,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   408,     0,    82,
      83,    84,    85,    86,     0,     0,     0,     0,   379,     0,
       0,     0,    87,    88,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,  1045,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,  1046,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,  1096,     0,    82,    83,    84,    85,
      86,     0,     0,     0,     0,   379,     0,     0,     0,    87,
      88,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
    1098,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1099,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   408,     0,    82,    83,    84,    85,    86,     0,     0,
       0,     0,  1100,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   762,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   763,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   408,     0,
      82,    83,    84,    85,    86,     0,     0,     0,     0,   379,
       0,     0,     0,    87,    88,     0,     0,     0,     0,     0,
       0,    89,   833,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   834,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,    81,     0,    82,    83,    84,
      85,    86,     0,     0,     0,     0,   379,     0,     0,     0,
      87,    88,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   408,     0,    82,    83,    84,    85,    86,     0,
       0,     0,     0,   379,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   408,
       0,    82,    83,    84,    85,    86,     0,     0,     0,     0,
     379,     0,     0,     0,    87,    88,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   408,     0,    82,    83,
      84,    85,    86,     0,     0,     0,     0,   379,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   408,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,   379,     0,     0,     0,    87,    88,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1034,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     408,     0,    82,    83,    84,    85,    86,     0,     0,     0,
       0,   379,     0,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   408,     0,    82,
      83,    84,    85,    86,     0,     0,     0,     0,   379,     0,
       0,     0,    87,    88,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379
};

static const yytype_int16 yycheck[] =
{
      57,   400,   405,   399,   754,   742,     4,    64,     4,     4,
       4,   737,   400,    22,    22,  1125,   127,   157,   188,   188,
     230,    78,   114,   188,   531,   532,   188,   188,   239,     4,
      87,    88,    89,   432,   101,    92,    93,     4,   188,   239,
       4,   132,    99,   727,   728,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,    41,   467,   468,
     469,   470,   471,   472,   176,   474,   475,   241,    16,    11,
     181,   531,   532,   482,   483,   484,   485,   486,   487,   104,
      22,   490,     4,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
       4,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   529,     4,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   185,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,  1465,     8,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   114,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     104,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,     4,   664,   665,   666,   667,   668,
     669,  1447,   113,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   114,   692,   693,   694,   114,   696,  1629,   176,
    1544,   239,   701,   702,   703,   704,   705,   706,   707,   530,
     530,   709,   379,    12,    13,    14,    15,    16,    17,    18,
     530,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   166,  1678,   156,  1680,   230,   185,
      79,   739,  1685,     4,  1080,   412,   413,   239,   185,     4,
      90,   531,   532,   532,   176,   530,     4,   424,   176,   531,
     532,   532,   429,    42,  1695,     4,   530,     4,   154,   115,
     109,   226,     4,     8,   530,   114,   530,   533,    10,   533,
     530,   127,  1142,  1119,  1504,    20,    41,   102,   234,    28,
     245,    28,  1512,  1569,     4,    74,     6,   234,     4,   114,
    1136,  1577,   101,     4,    10,   144,   473,   115,   807,    70,
     230,   532,  1743,   115,  1757,  1758,  1660,  1760,  1616,   127,
     530,   488,   489,   533,  1622,   127,   211,   529,    12,    13,
      14,    15,    16,    17,    18,   834,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    12,
      13,    14,    15,    16,    17,    18,   531,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      12,    13,    14,    15,    16,    17,    18,    78,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    12,    13,    14,    15,    16,    17,    18,   238,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   531,   531,   229,   530,  1210,  1211,  1638,   154,
     530,   182,     4,   533,   532,    22,   532,   532,   532,    12,
      13,    14,    15,    16,    17,    18,   531,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    1527,   531,   532,   154,   621,   532,   529,   531,    12,    13,
      14,    15,    16,    17,    18,   530,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    55,  1562,    57,    12,    13,    14,
      15,    16,    17,    18,   661,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    90,  1450,
    1451,  1452,  1453,  1454,    12,    13,    14,    15,    16,    17,
      18,   104,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,  1034,    95,   530,   530,   531,
     533,  1455,   530,   710,    27,   533,    29,   714,   715,   716,
     717,   718,   529,     4,  1631,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,  1458,   115,
       4,   530,  1540,  1541,   533,    11,   530,     6,     7,     8,
       9,   127,  1091,  1441,     4,  1443,   530,     4,  1446,   533,
    1437,  1100,  1091,  1429,   761,  1509,  1432,  1444,   532,    15,
      16,  1461,    18,   530,  1464,   530,   533,  1497,   533,   531,
     532,   778,   779,     4,   532,  1124,   530,   532,  1127,   533,
    1118,   530,  1128,  1591,   533,   530,  1594,  1595,   533,   532,
    1598,    12,    13,    14,    15,    16,    17,    18,  1151,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,  1510,  1152,    64,   532,   238,  1515,     4,   530,
     530,     4,   533,   533,  1138,  1139,  1556,     4,     0,   532,
     532,   532,  1586,  1587,    20,    12,    13,    14,    15,    16,
      17,    18,   532,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   530,   530,   105,   533,
     533,   530,    45,    46,   533,    48,   532,   117,   115,  1567,
    1568,   530,    55,   104,   533,   532,   126,  1575,  1576,   532,
     127,    79,   132,   114,   530,   532,   530,   533,  1642,   533,
    1644,    63,    78,    76,   533,    72,    73,    74,    75,   532,
     532,   530,   152,    86,   533,   532,   532,   532,    80,    81,
      93,   109,   532,   144,   532,   532,   114,   100,   532,   166,
     532,   532,     1,   532,   532,   532,   124,   532,   532,   532,
     532,   181,   532,   110,   111,   112,  1744,    26,   121,   122,
     532,   127,   532,  1641,    41,   532,   144,   532,   120,  1647,
    1581,  1582,  1583,  1584,  1585,  1709,   532,   531,   141,   142,
     210,  1769,   145,   146,   147,   532,   532,   532,   154,   532,
     532,   148,   149,   532,  1602,  1603,   532,  1605,  1606,  1607,
     166,  1609,  1610,  1611,    63,   532,   185,  1615,   171,  1617,
     532,  1619,   532,  1621,    26,    27,    28,    29,    30,    31,
      32,    80,    81,   532,   176,   188,   532,   184,     4,   533,
     532,   532,   532,   185,   532,   198,   188,   189,   190,   191,
     192,   193,   532,   532,   196,   197,   532,   532,   532,     4,
     533,   532,   215,   216,   217,   532,   532,   532,   224,   532,
     532,   120,  1049,   532,   532,   532,   218,   532,   532,   532,
      28,   533,   235,   236,   532,   227,   532,   229,  1671,  1672,
     532,  1674,  1675,  1676,   532,   532,  1679,   244,  1681,   532,
    1683,  1684,   533,   532,  1423,   532,  1425,  1426,  1427,   532,
     532,   532,   532,   532,  1423,  1092,  1093,   532,   532,   532,
     532,   532,   532,  1100,   532,   163,   532,   176,    25,    26,
      27,    28,    29,    30,    31,    32,   185,   530,   532,   188,
     189,   190,   191,   192,   193,   532,   532,   196,   197,   532,
     532,   126,   532,   532,  1473,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   530,   532,     4,   218,
     532,   532,   532,     4,   532,   532,  1485,  1154,   227,  1156,
     229,   532,   532,   532,   532,   532,  1505,   532,   532,   532,
     532,   532,   532,   532,  1513,   530,    12,    13,    14,    15,
      16,    17,    18,   532,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   532,   532,   532,
     532,   532,   530,    12,    13,    14,    15,    16,    17,    18,
     532,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    12,    13,    14,    15,    16,    17,
      18,   532,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    12,    13,    14,    15,    16,
      17,    18,   532,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    12,    13,    14,    15,
      16,    17,    18,   533,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   532,   532,   532,
       4,   532,     4,   532,   532,     4,   532,    43,    12,    13,
      14,    15,    16,    17,    18,   532,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   530,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       4,   532,   532,   532,   532,    81,   532,   104,    12,    13,
      14,    15,    16,    17,    18,   532,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    12,    13,    14,    15,    16,    17,    18,  1375,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   532,   532,   532,   532,   532,   532,    39,   532,
     532,   532,   238,   532,   532,   214,    13,    14,    15,    16,
      17,    18,   532,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   214,  1424,    12,    13,
      14,    15,    16,    17,    18,   532,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    24,
      25,    26,    27,    28,    29,    30,    31,    32,  1455,   532,
     532,   532,   532,     4,   532,  1462,   532,   532,   532,   532,
     532,   532,     4,   532,     6,     7,     8,     9,    10,   532,
     532,  1478,   532,   532,   532,   532,   532,    19,    20,   532,
     532,   532,   532,   532,   532,    27,   532,   532,   532,   532,
     532,  1498,  1499,   532,   532,   532,   532,   532,   532,   532,
       4,   532,  1509,   532,    46,   532,   532,   532,   532,   532,
     532,    53,   532,   532,   532,   532,   532,   532,    14,    15,
      16,    17,    18,  1530,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   532,   532,   532,
     532,   532,   532,   532,  1551,   532,   532,  1554,  1555,    15,
      16,    17,    18,    95,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,  1586,
    1587,   123,    15,    16,    17,    18,   532,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     532,   532,   532,   532,   532,     4,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,  1633,   532,   532,   532,
    1637,   532,   532,   532,   532,  1642,   532,  1644,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,     4,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   239,   533,   533,
     533,   533,   107,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   532,   532,  1691,   533,   533,   748,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,  1709,   533,   533,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     4,
     533,     6,     7,     8,     9,    10,   533,   533,   533,   533,
     532,   533,   533,   533,    19,    20,   533,   533,   533,   533,
     533,   533,    27,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,    46,   533,   533,   533,   533,   533,   533,    53,    32,
     533,   533,   533,   533,   533,   533,   533,   161,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,     4,   533,   533,
      95,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   123,   533,
       4,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,     4,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   126,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,     4,   533,     6,     7,
       8,     9,    10,   533,   533,   533,   533,   532,   533,   533,
     533,    19,    20,   533,   533,   533,   532,   532,   156,    27,
     126,     4,   533,   533,   123,   533,   533,   533,   533,    50,
     133,   157,   532,   101,     4,     4,   532,   532,    46,   127,
       4,   533,   533,    50,   108,    53,   533,   533,   533,   533,
     533,   127,     4,   126,   532,   532,   532,   532,   532,   532,
      22,   532,   532,   532,   532,   530,   533,   227,   532,     4,
     532,   532,    46,   532,   532,   532,    22,     7,     6,     4,
       7,     7,   124,     4,   533,   533,     6,    95,   154,   127,
       7,   188,     6,     6,   530,   533,     6,    19,   710,  1535,
     386,    60,  1536,  1505,  1644,  1543,    49,  1513,  1120,    38,
     414,   430,  1682,    -1,    -1,   123,    -1,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,     4,    -1,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,   532,   533,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
       4,    -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   532,   533,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   206,   207,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,     4,    -1,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,     4,    -1,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,     4,    -1,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,     4,    -1,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,     4,    -1,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,     4,    -1,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   532,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     4,
      -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,     4,    -1,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,     4,    -1,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
       4,    -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,     4,    -1,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   532
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    63,    80,    81,   120,   176,   185,   188,   189,
     190,   191,   192,   193,   196,   197,   218,   227,   229,   535,
     536,   537,   538,   570,   571,   575,   577,   585,   587,   588,
     589,   593,   595,   609,   610,   612,   613,   614,   615,   617,
       4,    70,   182,   608,     4,     4,    78,   154,   616,   188,
     101,   619,     4,     4,     0,   536,   529,   550,   572,   579,
     579,   579,   590,    16,   239,   539,     4,    10,   611,   618,
     621,   113,   594,   594,   211,   531,   616,     4,    22,   531,
     529,     4,     6,     7,     8,     9,    10,    19,    20,    27,
      28,    36,    46,    53,    78,    83,    84,    95,   109,   123,
     154,   205,   206,   207,   210,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   532,
     551,   552,   591,   622,   626,     4,   104,   114,   144,   573,
      79,   109,   114,   124,   144,   580,   580,   114,   144,     4,
     532,   553,   554,   555,   558,   569,     4,     6,     4,   622,
       4,    10,    11,    22,   530,    95,     4,     4,   594,     4,
     622,     4,   531,   532,    11,   622,   622,   622,   622,   238,
     622,   627,   532,   622,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   622,   104,
     530,    41,   556,   557,    12,    13,    14,    15,    16,    17,
      18,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    26,   531,   574,     4,   573,   104,
     530,     4,     4,   531,   557,   538,   553,   188,   530,    64,
     117,   132,   152,   181,   210,   559,   561,   556,   531,   532,
     622,    46,    78,   154,   620,   622,   621,     4,     4,    28,
     533,   622,   623,   624,   622,   622,   627,     4,    90,   238,
     538,     4,    72,    73,    74,    75,   110,   111,   112,   148,
     149,   184,   244,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,    83,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   533,   623,   623,   623,
     623,   623,   623,    28,    83,   622,   623,   623,   533,   533,
     533,   533,   533,   533,   623,   623,   623,   623,   623,   623,
     622,   622,   623,   533,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   533,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   533,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   533,   533,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     533,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   533,   622,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   533,   623,   623,
     533,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   533,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   622,   623,   623,   533,   623,
     623,   623,   623,   623,    83,   623,   533,   533,   623,   623,
     623,   623,   623,   623,   623,    49,   130,   220,   623,   625,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   533,   533,   623,   623,   623,   533,   623,   533,   533,
     533,   533,   623,   623,   623,   623,   623,   623,   623,   533,
     553,   552,     4,   622,   622,   622,   622,   622,     8,    20,
     154,   532,    15,    16,    18,   622,     4,    36,    40,   154,
     532,   622,   622,   622,   622,   622,   626,   622,   626,   622,
     622,   622,   622,   622,   622,    28,   531,   539,   230,   553,
       4,   188,   531,   532,   581,   188,   531,   581,     4,   102,
     114,   229,   566,   533,   533,     4,   592,   554,   132,   181,
     562,   555,   126,   163,   560,     4,   114,   176,   531,   532,
     606,   607,   530,   533,   214,     4,    90,   622,   622,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   623,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     623,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     530,   530,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   104,   533,   533,   533,   533,
     533,   533,   533,   623,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   622,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   539,     8,   154,   538,
     623,   622,   622,   532,    39,   532,   532,   532,   538,     4,
     161,   545,   553,   539,   574,   584,   618,     4,     4,   549,
     234,   538,   576,   584,     4,   234,   538,   586,   557,   115,
     127,   115,   127,   115,   127,    22,   531,   530,   539,   560,
     560,   126,   156,   555,   126,     4,   105,   115,   127,   166,
     596,   597,   598,   556,   623,   622,   622,     4,   214,   533,
     533,   626,   626,   622,   533,   104,   107,   540,   533,   533,
     538,   623,   622,   538,   538,   538,   533,   539,    50,   133,
     547,   539,   157,   578,   188,   581,   530,   533,   578,   532,
     582,   578,   188,   581,   578,   582,   566,   101,   567,   567,
     567,   567,   567,   567,   591,     4,     4,   545,   555,   622,
     156,   230,   563,   564,   565,   555,   532,   606,   115,   127,
     532,   532,   127,   530,   533,     4,   538,     4,   622,   533,
     533,   101,   533,   623,    50,   108,   544,   533,   533,   533,
     533,   533,   545,   546,   622,   622,   127,   584,   538,   576,
       4,   583,   591,   530,   578,   584,   538,   586,   578,   126,
     532,   532,   532,   532,   532,   532,    22,    22,   531,   547,
     622,   532,   565,   596,   532,   532,   549,   549,   532,   597,
     606,     4,    45,    46,    48,    55,    76,    86,    93,   100,
     121,   122,   141,   142,   145,   146,   147,   171,   188,   198,
     215,   216,   217,   235,   236,   604,   622,   533,   541,   622,
     622,   545,   547,   530,    43,    81,   542,   530,   227,   578,
     578,   582,   530,   533,   532,   578,   578,   582,     4,   166,
     568,   568,   568,   568,   568,   568,   591,   591,     4,   549,
     533,   549,   549,   533,   533,   549,   532,   600,   600,   600,
     600,   600,   600,   532,   600,   600,   600,    46,   601,   600,
     601,   600,   532,   600,   600,   601,   532,   532,   599,   533,
     241,   530,   543,   542,   547,   622,   622,   584,   578,   591,
     583,   578,   530,   533,   533,   533,   533,   533,   533,    22,
     533,   606,   533,   533,   533,     7,   602,   603,   602,   602,
       6,   605,   602,   602,   602,   603,   602,   603,   602,   605,
     602,   602,   603,     7,     7,     4,    20,    78,   127,   154,
     166,   224,     4,   622,   124,   548,   542,   533,     4,   591,
     530,   533,   226,   245,    55,    57,   530,   533,   533,   533,
     533,     6,   154,     6,     7,     8,     9,   127,   127,   532,
     542,   549,     7,   188,     6,     6,   603,   603,   603,   549,
     533,     6,   533
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 902 "sql.y"
    {
    /* TODO  free curStmt */
    curStmt = NULL;
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 906 "sql.y"
    {
        stmtArray[indexArray] = curStmt;
        indexArray++;
        curStmt = NULL;
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 911 "sql.y"
    {
        stmtArray[indexArray] = curStmt;
        indexArray++;
        curStmt = NULL;
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 921 "sql.y"
    { 
  debug("STMT");
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 925 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("select From %p to child %p", curStmt, stmt);
        curStmt = stmt;
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 936 "sql.y"
    { 
        curStmt->sql_command = SQLCOM_SELECT; 
        debug("SELECTNODATA %d %d", (yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval));
        (yyval.stmt) = curStmt;
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 944 "sql.y"
    { 
      curStmt->sql_command = SQLCOM_SELECT; 
      debug("SELECT %d %d %d", (yyvsp[(2) - (11)].intval), (yyvsp[(3) - (11)].intval), (yyvsp[(5) - (11)].intval)); 

      resolve_select_expr(curStmt);

      (yyval.stmt) = curStmt;
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 955 "sql.y"
    {
        debug("WHERE");
        listAddNodeTail(curStmt->whereList, (yyvsp[(2) - (2)].item));
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 961 "sql.y"
    { 
        debug("GROUPBYLIST %d %d", (yyvsp[(3) - (4)].intval), (yyvsp[(4) - (4)].intval)); 
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 966 "sql.y"
    { 
        debug("GROUPBY1 %d",  (yyvsp[(2) - (2)].intval)); 
        (yyval.intval) = 1;
        listAddNodeTail(curStmt->groupList, (yyvsp[(1) - (2)].item));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 971 "sql.y"
    { 
        debug("GROUPBY2 %d",  (yyvsp[(4) - (4)].intval)); 
        (yyval.intval) = (yyvsp[(1) - (4)].intval) + 1;
        listAddNodeTail(curStmt->groupList, (yyvsp[(3) - (4)].item));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 978 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 979 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 980 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 983 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 984 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 987 "sql.y"
    {
        debug("HAVING");
        listAddNodeTail(curStmt->havingList, (yyvsp[(2) - (2)].item)); 
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 993 "sql.y"
    { 
        debug("ORDERBYLIST %d", (yyvsp[(3) - (3)].intval)); 
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 997 "sql.y"
    { 
        debug("ORDERBY 1 %d",  (yyvsp[(2) - (2)].intval)); 
        (yyvsp[(1) - (2)].item)->isDesc = (yyvsp[(2) - (2)].intval);
        listAddNodeTail(curStmt->orderList, (yyvsp[(1) - (2)].item));
        (yyval.intval) = 1;
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1003 "sql.y"
    {
        debug("ORDERBY 2 %d",  (yyvsp[(4) - (4)].intval)); 
        (yyvsp[(3) - (4)].item)->isDesc = (yyvsp[(4) - (4)].intval);
        listAddNodeTail(curStmt->orderList, (yyvsp[(3) - (4)].item));    
        (yyval.intval) = (yyvsp[(1) - (4)].intval) + 1; 
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1011 "sql.y"
    {
        debug("LIMIT 1"); 
        listAddNodeTail(curStmt->limitList, (yyvsp[(2) - (2)].item));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1015 "sql.y"
    { 
        debug("LIMIT 2"); 
        listAddNodeTail(curStmt->limitList, (yyvsp[(2) - (4)].item));
        listAddNodeTail(curStmt->limitList, (yyvsp[(4) - (4)].item));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1023 "sql.y"
    { debug("INTO %d", (yyvsp[(2) - (2)].intval)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1027 "sql.y"
    {
        debug("COLUMN %s", (yyvsp[(1) - (1)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(1) - (1)].strval));
        i->token1 = NAME;
        if (curStmt->step == InsertColumnStep) {
            listAddNodeTail(curStmt->insertList, i); 
        } else if (curStmt->step == UsingStep) {
            listAddNodeTail(curStmt->usingList, i); 
        }

        free((yyvsp[(1) - (1)].strval));
        (yyval.intval) = 1; 
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1041 "sql.y"
    {
        debug("COLUMN %s", (yyvsp[(3) - (3)].strval));
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(3) - (3)].strval));
        i->token1 = NAME;
        if (curStmt->step == InsertColumnStep) {
            listAddNodeTail(curStmt->insertList, i); 
        } else if (curStmt->step == UsingStep) {
            listAddNodeTail(curStmt->usingList, i); 
        }

        free((yyvsp[(3) - (3)].strval));
        (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1057 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1058 "sql.y"
    { if((yyval.intval) & 01) yyerror("duplicate ALL option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 01; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1059 "sql.y"
    { if((yyval.intval) & 02) yyerror("duplicate DISTINCT option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 02; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1060 "sql.y"
    { if((yyval.intval) & 04) yyerror("duplicate DISTINCTROW option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 04; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1061 "sql.y"
    { if((yyval.intval) & 010) yyerror("duplicate HIGH_PRIORITY option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 010; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1062 "sql.y"
    { if((yyval.intval) & 020) yyerror("duplicate STRAIGHT_JOIN option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 020; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1063 "sql.y"
    { if((yyval.intval) & 040) yyerror("duplicate SQL_SMALL_RESULT option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 040; ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1064 "sql.y"
    { if((yyval.intval) & 0100) yyerror("duplicate SQL_BIG_RESULT option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 0100; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1065 "sql.y"
    { if((yyval.intval) & 0200) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); (yyval.intval) = (yyvsp[(1) - (2)].intval) | 0200; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1068 "sql.y"
    {
        debug("#####%p\n", (yyvsp[(1) - (1)].item));
        listAddNodeTail(curStmt->select_expr_list, (yyvsp[(1) - (1)].item));
        (yyval.intval) = 1;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1073 "sql.y"
    {
        debug("#####%p\n", (yyvsp[(3) - (3)].item));
        listAddNodeTail(curStmt->select_expr_list, (yyvsp[(3) - (3)].item));
        (yyval.intval) = 1;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1078 "sql.y"
    { debug("SELECT *");
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup("*");
        i->token1 = NAME;
        listAddNodeTail(curStmt->select_expr_list, i);
        (yyval.intval) = 1;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1086 "sql.y"
    {
        debug("SIMPLE SELECT");
        if ((yyvsp[(2) - (2)].strval)) {
            (yyvsp[(1) - (2)].item)->alias = strdup((yyvsp[(2) - (2)].strval));
            free((yyvsp[(2) - (2)].strval));
        }
        (yyval.item) = (yyvsp[(1) - (2)].item);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1093 "sql.y"
    { debug("SELECT %s.*", (yyvsp[(1) - (3)].strval));
        Item *i = calloc(1, sizeof(*i));
        i->prefix = strdup((yyvsp[(1) - (3)].strval));
        i->name = strdup("*");
        i->token1 = NAME;
        (yyval.item) = i;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1099 "sql.y"
    { 
	    /* (Successful) attempt to remove functions from consideration */
	    Item *i = calloc(1,sizeof(*i));
	    i->prefix = NULL;
	    i->name = strdup((yyvsp[(1) - (3)].strval));
	    i->token1 = FUNCTION;
	    (yyval.item) = i;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1109 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1110 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1119 "sql.y"
    { debug("TABLE %s", (yyvsp[(1) - (3)].strval)); 
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(1) - (3)].strval));
        free((yyvsp[(1) - (3)].strval));

        if ((yyvsp[(2) - (3)].strval)) {
            t->alias = strdup((yyvsp[(2) - (3)].strval));
            free((yyvsp[(2) - (3)].strval));
        }

        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1132 "sql.y"
    { 
        debug("TABLE %s.%s", (yyvsp[(1) - (5)].strval), (yyvsp[(3) - (5)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(1) - (5)].strval));
        t->name = strdup((yyvsp[(3) - (5)].strval));
        free((yyvsp[(1) - (5)].strval));
        free((yyvsp[(3) - (5)].strval));

        if ((yyvsp[(4) - (5)].strval)) {
            t->alias = strdup((yyvsp[(4) - (5)].strval));
            free((yyvsp[(4) - (5)].strval));
        }

        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1147 "sql.y"
    {
        debug("SUBQUERYAS %s", (yyvsp[(3) - (3)].strval));
        Table *t = calloc(1, sizeof(*t)); 
        t->sub = (yyvsp[(1) - (3)].stmt);
        if ((yyvsp[(3) - (3)].strval)) {
            t->alias = strdup((yyvsp[(3) - (3)].strval));
            free((yyvsp[(3) - (3)].strval));
        }
        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1157 "sql.y"
    { debug("TABLEREFERENCES %d", (yyvsp[(2) - (3)].intval)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1164 "sql.y"
    { debug ("ALIAS %s", (yyvsp[(2) - (2)].strval)); (yyval.strval)=(yyvsp[(2) - (2)].strval) ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1165 "sql.y"
    {(yyval.strval) = NULL;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1170 "sql.y"
    { debug("JOIN %d", 0100+(yyvsp[(2) - (5)].intval)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1172 "sql.y"
    { debug("JOIN %d", 0200); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1174 "sql.y"
    { debug("JOIN %d", 0200); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1176 "sql.y"
    { debug("JOIN %d", 0300+(yyvsp[(2) - (6)].intval)+(yyvsp[(3) - (6)].intval)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1178 "sql.y"
    { debug("JOIN %d", 0400+(yyvsp[(3) - (5)].intval)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1181 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1182 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1183 "sql.y"
    { (yyval.intval) = 2; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1186 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1187 "sql.y"
    {(yyval.intval) = 4; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1190 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1191 "sql.y"
    { (yyval.intval) = 2; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1194 "sql.y"
    { (yyval.intval) = 1 + (yyvsp[(2) - (2)].intval); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1195 "sql.y"
    { (yyval.intval) = 2 + (yyvsp[(2) - (2)].intval); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1196 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1201 "sql.y"
    {
        curStmt->step = UsingStep;  
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1206 "sql.y"
    {
        debug("ONEXPR");
        listAddNodeTail(curStmt->whereList, (yyvsp[(2) - (2)].item)); 
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1210 "sql.y"
    { debug("USING %d", (yyvsp[(3) - (4)].intval)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1214 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 010+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = USE;
        i->token2 = KEY;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1220 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 020+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = IGNORE;
        i->token2 = KEY;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1226 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 030+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = FORCE;
        i->token2 = KEY;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1232 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 010+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = USE;
        i->token2 = INDEX;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1238 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 020+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = IGNORE;
        i->token2 = INDEX;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1244 "sql.y"
    {
        debug("INDEXHINT %d %d", (yyvsp[(5) - (6)].listval), 030+(yyvsp[(3) - (6)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = FORCE;
        i->token2 = INDEX;
        i->right = (yyvsp[(5) - (6)].listval);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1253 "sql.y"
    { (yyval.intval) = 1; /* TODO what this ?*/;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1254 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1257 "sql.y"
    { debug("INDEX %s", (yyvsp[(1) - (1)].strval));
        list *l = listCreate();
        char *s = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
        listAddNodeTail(l, s);
        (yyval.listval) = l;
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1263 "sql.y"
    { debug("INDEX primary");
        list *l = listCreate();
        char *s = strdup("PRIMARY");
        listAddNodeTail(l, s);
        (yyval.listval) = l;
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1268 "sql.y"
    { debug("INDEX %s", (yyvsp[(3) - (3)].strval));
        char *s = strdup((yyvsp[(3) - (3)].strval));
        listAddNodeTail((yyvsp[(1) - (3)].listval), s);
        free((yyvsp[(3) - (3)].strval));
        (yyval.listval) = (yyvsp[(1) - (3)].listval);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1275 "sql.y"
    { 
  debug("SUBQUERY From child %p to father %p", curStmt, curStmt->father);   
  curStmt = curStmt->father;
  (yyval.stmt) = (yyvsp[(2) - (3)].stmt);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1282 "sql.y"
    { debug("STMT"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1285 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("delete From %p to child %p", curStmt, stmt);
        curStmt = stmt;
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1296 "sql.y"
    {
        debug("DELETEONE %d %s", (yyvsp[(2) - (7)].intval), (yyvsp[(4) - (7)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (7)].strval));
        free((yyvsp[(4) - (7)].strval));
        listAddNodeTail(curStmt->joinList, t);
        curStmt->sql_command = SQLCOM_DELETE;
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1307 "sql.y"
    {
        debug("DELETEONE %d %s", (yyvsp[(2) - (9)].intval), (yyvsp[(4) - (9)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(4) - (9)].strval));
        t->name = strdup((yyvsp[(6) - (9)].strval));
        free((yyvsp[(4) - (9)].strval));
        listAddNodeTail(curStmt->joinList, t);
        curStmt->sql_command = SQLCOM_DELETE;
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1318 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) + 01; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1320 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) + 04; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1321 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1327 "sql.y"
    { debug("DELETEMULTI %d %d %d", (yyvsp[(2) - (6)].intval), (yyvsp[(3) - (6)].intval), (yyvsp[(5) - (6)].intval)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1329 "sql.y"
    { debug("TABLE %s", (yyvsp[(1) - (2)].strval)); free((yyvsp[(1) - (2)].strval)); (yyval.intval) = 1; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1331 "sql.y"
    { debug("TABLE %s", (yyvsp[(3) - (4)].strval)); free((yyvsp[(3) - (4)].strval)); (yyval.intval) = (yyvsp[(1) - (4)].intval) + 1; ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1339 "sql.y"
    { debug("DELETEMULTI %d %d %d", (yyvsp[(2) - (7)].intval), (yyvsp[(4) - (7)].intval), (yyvsp[(6) - (7)].intval)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1344 "sql.y"
    { debug("STMT"); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1347 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("insert From %p to child %p", curStmt, stmt);
        stmt->sql_command = SQLCOM_INSERT;
        stmt->step = InsertColumnStep;
        curStmt = stmt;
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1360 "sql.y"
    {
        curStmt->step = ValueColumnStep;
        curStmt->valueChildList = listCreate();
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1369 "sql.y"
    {
        debug("INSERTVALS %d %d %s", (yyvsp[(2) - (8)].intval), (yyvsp[(7) - (8)].intval), (yyvsp[(4) - (8)].strval)); 
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (8)].strval));
        free((yyvsp[(4) - (8)].strval));
        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1380 "sql.y"
    {
        debug("INSERTVALS %d %d %s", (yyvsp[(2) - (10)].intval), (yyvsp[(9) - (10)].intval), (yyvsp[(4) - (10)].strval)); 
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(6) - (10)].strval));
        t->db = strdup((yyvsp[(4) - (10)].strval));
        free((yyvsp[(4) - (10)].strval));
        free((yyvsp[(6) - (10)].strval));
        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1392 "sql.y"
    { debug("DUPUPDATE %d", (yyvsp[(4) - (4)].intval)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1395 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1396 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 01 ; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1397 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 02 ; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1398 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 04 ; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1399 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 010 ; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1407 "sql.y"
    { debug("INSERTCOLS %d", (yyvsp[(2) - (3)].intval)); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1410 "sql.y"
    {
        debug("VALUES %d", (yyvsp[(2) - (3)].intval)); (yyval.intval) = 1;
        listAddNodeTail(curStmt->valueList, curStmt->valueChildList);  
        curStmt->valueChildList = listCreate();
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1415 "sql.y"
    { 
        debug("VALUES %d", (yyvsp[(4) - (5)].intval)); (yyval.intval) = (yyvsp[(1) - (5)].intval) + 1; 
        listAddNodeTail(curStmt->valueList, curStmt->valueChildList);  
        curStmt->valueChildList = listCreate();
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1421 "sql.y"
    {
        debug("expr");
        listAddNodeTail(curStmt->valueChildList, (yyvsp[(1) - (1)].item));
        (yyval.intval) = 1;
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1425 "sql.y"
    {
        debug(", expr "); 
        (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1;
        listAddNodeTail(curStmt->valueChildList, (yyvsp[(3) - (3)].item));
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1434 "sql.y"
    {
        debug("INSERTASGN %d %d %s", (yyvsp[(2) - (7)].intval), (yyvsp[(6) - (7)].intval), (yyvsp[(4) - (7)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (7)].strval));
        listAddNodeTail(curStmt->joinList, t);
        free((yyvsp[(4) - (7)].strval));
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1444 "sql.y"
    {
        debug("INSERTASGN %d %d %s", (yyvsp[(2) - (9)].intval), (yyvsp[(6) - (9)].strval), (yyvsp[(4) - (9)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(4) - (9)].strval));
        t->name = strdup((yyvsp[(6) - (9)].strval));
        listAddNodeTail(curStmt->joinList, t);
        free((yyvsp[(4) - (9)].strval));
        free((yyvsp[(6) - (9)].strval));
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1457 "sql.y"
    {
        debug("INSERTSELECT %d %s From child %p to father %p", (yyvsp[(2) - (7)].intval), (yyvsp[(4) - (7)].strval), curStmt, curStmt->father);
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (7)].strval));
        free((yyvsp[(4) - (7)].strval));
        curStmt = curStmt->father;
        listAddNodeTail(curStmt->joinList, t);
        curStmt->valueSelect = (yyvsp[(6) - (7)].stmt);
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1469 "sql.y"
    {
        debug("INSERTSELECT %d %s From child %p to father %p", (yyvsp[(2) - (9)].intval), (yyvsp[(4) - (9)].strval), curStmt, curStmt->father);
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(6) - (9)].strval));
        t->db = strdup((yyvsp[(4) - (9)].strval));
        free((yyvsp[(4) - (9)].strval));
        free((yyvsp[(6) - (9)].strval));
        curStmt = curStmt->father;
        listAddNodeTail(curStmt->joinList, t);
        curStmt->valueSelect = (yyvsp[(8) - (9)].stmt);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1500 "sql.y"
    { debug("STMT"); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1503 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("replace From %p to child %p", curStmt, stmt);
        stmt->sql_command = SQLCOM_REPLACE;
        stmt->step = InsertColumnStep;
        curStmt = stmt;
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1515 "sql.y"
    {
        curStmt->step = ValueColumnStep;
        curStmt->valueChildList = listCreate();
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1523 "sql.y"
    {
        debug("REPLACEVALS %d %d %s", (yyvsp[(2) - (8)].intval), (yyvsp[(7) - (8)].intval), (yyvsp[(4) - (8)].strval)); 
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (8)].strval));
        free((yyvsp[(4) - (8)].strval));
        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1533 "sql.y"
    {
        debug("REPLACEVALS %d %d %s", (yyvsp[(2) - (10)].intval), (yyvsp[(9) - (10)].intval), (yyvsp[(6) - (10)].strval)); 
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(4) - (10)].strval));
        t->name = strdup((yyvsp[(4) - (10)].strval));
        free((yyvsp[(4) - (10)].strval));
        free((yyvsp[(6) - (10)].strval));
        listAddNodeTail(curStmt->joinList, t);
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1546 "sql.y"
    {
        debug("REPLACEASGN %d %d %s", (yyvsp[(2) - (7)].intval), (yyvsp[(6) - (7)].intval), (yyvsp[(4) - (7)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(4) - (7)].strval));
        listAddNodeTail(curStmt->joinList, t);
        free((yyvsp[(4) - (7)].strval));
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1557 "sql.y"
    {
        debug("REPLACEASGN %d %d %s", (yyvsp[(2) - (9)].intval), (yyvsp[(6) - (9)].strval), (yyvsp[(4) - (9)].strval));
        Table *t = calloc(1, sizeof(*t));
        t->db = strdup((yyvsp[(4) - (9)].strval));
        t->name = strdup((yyvsp[(6) - (9)].strval));
        listAddNodeTail(curStmt->joinList, t);
        free((yyvsp[(4) - (9)].strval));
        free((yyvsp[(6) - (9)].strval));
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1570 "sql.y"
    {
        debug("REPLACESELECT %d %s From child %p to father %p", (yyvsp[(2) - (7)].intval), (yyvsp[(4) - (7)].strval), curStmt, curStmt->father);
        Table *t = calloc(1, sizeof(*t));
        t->name = strdup((yyvsp[(4) - (7)].strval));
        free((yyvsp[(4) - (7)].strval));
        curStmt = curStmt->father;
        listAddNodeTail(curStmt->joinList, t);
        curStmt->valueSelect = (yyvsp[(6) - (7)].stmt);
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1582 "sql.y"
    {
        debug("REPLACESELECT %d %s From child %p to father %p", (yyvsp[(2) - (9)].intval), (yyvsp[(4) - (9)].strval), curStmt, curStmt->father);
        Table *t = calloc(1, sizeof(*t));
        t->db= strdup((yyvsp[(4) - (9)].strval));
        t->name = strdup((yyvsp[(6) - (9)].strval));
        free((yyvsp[(4) - (9)].strval));
        free((yyvsp[(6) - (9)].strval));
        curStmt = curStmt->father;
        listAddNodeTail(curStmt->joinList, t);
        curStmt->valueSelect = (yyvsp[(8) - (9)].stmt);
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1595 "sql.y"
    { debug("STMT"); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1598 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("update From %p to child %p", curStmt, stmt);
        curStmt = stmt;
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1614 "sql.y"
    { debug("UPDATE %d %d %d", (yyvsp[(2) - (8)].intval), (yyvsp[(3) - (8)].intval), (yyvsp[(5) - (8)].intval)); 
        curStmt->sql_command = SQLCOM_UPDATE;    
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1622 "sql.y"
    { debug("update_opts"); (yyval.intval) = 0; ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1623 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 01 ; ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1624 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 010 ; ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1628 "sql.y"
    {
        debug(" NULL"); 
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup("NULL");
        i->token1 = NAME;

        (yyval.item) = i;
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1635 "sql.y"
    { (yyval.item) = (yyvsp[(1) - (1)].item);;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1636 "sql.y"
    {
        debug(" NULL"); 
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup("DEFAULT");
        i->token1 = NAME;

        (yyval.item) = i;
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1646 "sql.y"
    { 
        if ((yyvsp[(2) - (3)].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[(1) - (3)].strval));
        debug("ASSIGN %s %d", (yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].item));

        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(1) - (3)].strval));
        free((yyvsp[(1) - (3)].strval));
        i->token1 = NAME;
        Item *c = calloc(1, sizeof(*c));
        c->token1 = COMPARISON;
        c->token2 = (yyvsp[(2) - (3)].subtok);
        c->left = i;
        c->right = (yyvsp[(3) - (3)].item);

        listAddNodeTail(curStmt->updateSetList, c); 
        (yyval.intval) = 1;
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1663 "sql.y"
    { 
        if ((yyvsp[(4) - (5)].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[(1) - (5)].strval));
        debug("ASSIGN %s.%s", (yyvsp[(1) - (5)].strval), (yyvsp[(3) - (5)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->prefix = strdup((yyvsp[(1) - (5)].strval));
        i->name = strdup((yyvsp[(3) - (5)].strval));
        free((yyvsp[(1) - (5)].strval));
        free((yyvsp[(3) - (5)].strval));
        i->token1 = NAME;
        Item *c = calloc(1, sizeof(*c));
        c->token1 = COMPARISON;
        c->token2 = (yyvsp[(4) - (5)].subtok);
        c->left = i;
        c->right = (yyvsp[(5) - (5)].item);

        listAddNodeTail(curStmt->updateSetList, c); 
        (yyval.intval) = 1; 
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1681 "sql.y"
    { 
        if ((yyvsp[(4) - (5)].subtok) != 4) yyerror("bad insert assignment to %s", (yyvsp[(3) - (5)].strval));
        debug("ASSIGN %s.%s", (yyvsp[(3) - (5)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(3) - (5)].strval));
        free((yyvsp[(3) - (5)].strval));
        i->token1 = NAME;
        Item *c = calloc(1, sizeof(*c));
        c->token1 = COMPARISON;
        c->token2 = (yyvsp[(4) - (5)].subtok);
        c->left = i;
        c->right = (yyvsp[(5) - (5)].item);

        listAddNodeTail(curStmt->updateSetList, c); 
        (yyval.intval) = (yyvsp[(1) - (5)].intval) + 1;
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1697 "sql.y"
    { 
        if ((yyvsp[(6) - (7)].subtok) != 4) yyerror("bad insert assignment to %s.$s", (yyvsp[(3) - (7)].strval), (yyvsp[(5) - (7)].strval));
        debug("ASSIGN %s.%s", (yyvsp[(3) - (7)].strval), (yyvsp[(5) - (7)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->prefix = strdup((yyvsp[(3) - (7)].strval));
        i->name = strdup((yyvsp[(5) - (7)].strval));
        free((yyvsp[(3) - (7)].strval));
        free((yyvsp[(5) - (7)].strval));
        i->token1 = NAME;
        Item *c = calloc(1, sizeof(*c));
        c->token1 = COMPARISON;
        c->token2 = (yyvsp[(6) - (7)].subtok);
        c->left = i;
        c->right = (yyvsp[(7) - (7)].item);

        listAddNodeTail(curStmt->updateSetList, c); 
        (yyval.intval) = (yyvsp[(1) - (7)].intval) + 1;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1719 "sql.y"
    { debug("STMT"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1723 "sql.y"
    { debug("CREATEDATABASE %d %s", (yyvsp[(3) - (4)].intval), (yyvsp[(4) - (4)].strval)); free((yyvsp[(4) - (4)].strval)); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1724 "sql.y"
    { debug("CREATEDATABASE %d %s", (yyvsp[(3) - (4)].intval), (yyvsp[(4) - (4)].strval)); free((yyvsp[(4) - (4)].strval)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1727 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1728 "sql.y"
    { if(!(yyvsp[(2) - (2)].subtok))yyerror("IF EXISTS doesn't exist");
                        (yyval.intval) = (yyvsp[(2) - (2)].subtok); /* NOT EXISTS hack */ ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1734 "sql.y"
    { debug("STMT"); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1738 "sql.y"
    { debug("CREATE %d %d %d %s", (yyvsp[(2) - (8)].intval), (yyvsp[(4) - (8)].intval), (yyvsp[(7) - (8)].intval), (yyvsp[(5) - (8)].strval)); free((yyvsp[(5) - (8)].strval)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1742 "sql.y"
    { debug("CREATE %d %d %d %s.%s", (yyvsp[(2) - (10)].intval), (yyvsp[(4) - (10)].intval), (yyvsp[(9) - (10)].intval), (yyvsp[(5) - (10)].strval), (yyvsp[(7) - (10)].strval));
                          free((yyvsp[(5) - (10)].strval)); free((yyvsp[(7) - (10)].strval)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1748 "sql.y"
    { debug("CREATESELECT %d %d %d %s", (yyvsp[(2) - (9)].intval), (yyvsp[(4) - (9)].intval), (yyvsp[(7) - (9)].intval), (yyvsp[(5) - (9)].strval)); free((yyvsp[(5) - (9)].strval)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1752 "sql.y"
    { debug("CREATESELECT %d %d 0 %s", (yyvsp[(2) - (6)].intval), (yyvsp[(4) - (6)].intval), (yyvsp[(5) - (6)].strval)); free((yyvsp[(5) - (6)].strval)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1757 "sql.y"
    { debug("CREATESELECT %d %d 0 %s.%s", (yyvsp[(2) - (11)].intval), (yyvsp[(4) - (11)].intval), (yyvsp[(5) - (11)].strval), (yyvsp[(7) - (11)].strval));
                              free((yyvsp[(5) - (11)].strval)); free((yyvsp[(7) - (11)].strval)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1762 "sql.y"
    { debug("CREATESELECT %d %d 0 %s.%s", (yyvsp[(2) - (8)].intval), (yyvsp[(4) - (8)].intval), (yyvsp[(5) - (8)].strval), (yyvsp[(7) - (8)].strval));
                          free((yyvsp[(5) - (8)].strval)); free((yyvsp[(7) - (8)].strval)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1766 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1767 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1770 "sql.y"
    { debug("STARTCOL"); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1771 "sql.y"
    { debug("COLUMNDEF %d %s", (yyvsp[(3) - (4)].intval), (yyvsp[(2) - (4)].strval)); free((yyvsp[(2) - (4)].strval)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1773 "sql.y"
    { debug("PRIKEY %d", (yyvsp[(4) - (5)].intval)); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1774 "sql.y"
    { debug("KEY %d", (yyvsp[(3) - (4)].intval)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1775 "sql.y"
    { debug("KEY %d", (yyvsp[(3) - (4)].intval)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1776 "sql.y"
    { debug("TEXTINDEX %d", (yyvsp[(4) - (5)].intval)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1777 "sql.y"
    { debug("TEXTINDEX %d", (yyvsp[(4) - (5)].intval)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1780 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1781 "sql.y"
    { debug("ATTR NOTNULL"); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1783 "sql.y"
    { debug("ATTR DEFAULT STRING %s", (yyvsp[(3) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1784 "sql.y"
    { debug("ATTR DEFAULT NUMBER %d", (yyvsp[(3) - (3)].intval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1785 "sql.y"
    { debug("ATTR DEFAULT FLOAT %g", (yyvsp[(3) - (3)].floatval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1786 "sql.y"
    { debug("ATTR DEFAULT BOOL %d", (yyvsp[(3) - (3)].intval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1787 "sql.y"
    { debug("ATTR AUTOINC"); (yyval.intval) = (yyvsp[(1) - (2)].intval) + 1; ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1788 "sql.y"
    { debug("ATTR UNIQUEKEY %d", (yyvsp[(4) - (5)].intval)); (yyval.intval) = (yyvsp[(1) - (5)].intval) + 1; ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1789 "sql.y"
    { debug("ATTR UNIQUEKEY"); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1790 "sql.y"
    { debug("ATTR PRIKEY"); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1791 "sql.y"
    { debug("ATTR PRIKEY"); (yyval.intval) = (yyvsp[(1) - (2)].intval) + 1; ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1792 "sql.y"
    { debug("ATTR COMMENT %s", (yyvsp[(3) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1795 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1796 "sql.y"
    { (yyval.intval) = (yyvsp[(2) - (3)].intval); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1797 "sql.y"
    { (yyval.intval) = (yyvsp[(2) - (5)].intval) + 1000*(yyvsp[(4) - (5)].intval); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1800 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1801 "sql.y"
    { (yyval.intval) = 4000; ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1804 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1805 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 1000; ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1806 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (2)].intval) | 2000; ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1810 "sql.y"
    { debug("COLCHARSET %s", (yyvsp[(4) - (4)].strval)); free((yyvsp[(4) - (4)].strval)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1811 "sql.y"
    { debug("COLCOLLATE %s", (yyvsp[(3) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1815 "sql.y"
    {
        (yyval.intval) = 10000 + (yyvsp[(2) - (2)].intval);
        
       /* | DATE { $$ = 100001; } 
       | TIME { $$ = 100002; }
       | TIMESTAMP { $$ = 100003; }
       | DATETIME { $$ = 100004; }
       | YEAR { $$ = 100005; }
       */
    /* } | NAME opt_binary opt_csc { $$ = 171000 + $2; */
    /*TEXT*/ 
    ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1827 "sql.y"
    { (yyval.intval) = 10000 + (yyvsp[(2) - (3)].intval); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1828 "sql.y"
    { (yyval.intval) = 20000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1829 "sql.y"
    { (yyval.intval) = 30000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1830 "sql.y"
    { (yyval.intval) = 40000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1831 "sql.y"
    { (yyval.intval) = 50000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1832 "sql.y"
    { (yyval.intval) = 60000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1833 "sql.y"
    { (yyval.intval) = 70000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1834 "sql.y"
    { (yyval.intval) = 80000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1835 "sql.y"
    { (yyval.intval) = 90000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1836 "sql.y"
    { (yyval.intval) = 110000 + (yyvsp[(2) - (3)].intval) + (yyvsp[(3) - (3)].intval); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1837 "sql.y"
    { (yyval.intval) = 120000 + (yyvsp[(2) - (3)].intval); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1838 "sql.y"
    { (yyval.intval) = 130000 + (yyvsp[(3) - (5)].intval); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1839 "sql.y"
    { (yyval.intval) = 140000 + (yyvsp[(2) - (2)].intval); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1840 "sql.y"
    { (yyval.intval) = 150000 + (yyvsp[(3) - (4)].intval); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1841 "sql.y"
    { (yyval.intval) = 160001; ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1842 "sql.y"
    { (yyval.intval) = 160002; ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1843 "sql.y"
    { (yyval.intval) = 160003; ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1844 "sql.y"
    { (yyval.intval) = 160004; ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1845 "sql.y"
    { (yyval.intval) = 170000 + (yyvsp[(2) - (3)].intval); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1846 "sql.y"
    { (yyval.intval) = 172000 + (yyvsp[(2) - (3)].intval); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1847 "sql.y"
    { (yyval.intval) = 173000 + (yyvsp[(2) - (3)].intval); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1848 "sql.y"
    { (yyval.intval) = 200000 + (yyvsp[(3) - (5)].intval); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1849 "sql.y"
    { (yyval.intval) = 210000 + (yyvsp[(3) - (5)].intval); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1852 "sql.y"
    { debug("ENUMVAL %s", (yyvsp[(1) - (1)].strval)); free((yyvsp[(1) - (1)].strval)); (yyval.intval) = 1; ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1853 "sql.y"
    { debug("ENUMVAL %s", (yyvsp[(3) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1856 "sql.y"
    { debug("CREATESELECT %d", (yyvsp[(1) - (3)].intval)) ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1859 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1860 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1861 "sql.y"
    { (yyval.intval) = 2; ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1864 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1865 "sql.y"
    { (yyval.intval) = 1;;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1869 "sql.y"
    { debug("stmt");;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1873 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->token1 = (yyvsp[(1) - (1)].intval);
        curStmt->show = i;
        stmt->sql_command = SQLCOM_SHOW_VARIABLES;
    ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1886 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        curStmt->show = i;
        stmt->sql_command = SQLCOM_SHOW_COLLATIONS;
    ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1900 "sql.y"
    {
        debug("show where");
        (yyval.intval)=0;
    ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1903 "sql.y"
    {
        debug("show like ");
        Item *i = curStmt->show;
        i->name = strdup((yyvsp[(3) - (3)].strval));
        free((yyvsp[(3) - (3)].strval));
    ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1908 "sql.y"
    {
        /* NAME for ? */
        debug("show like ");
        Item *i = curStmt->show;
        i->name = strdup((yyvsp[(3) - (3)].strval));
        free((yyvsp[(3) - (3)].strval));
    ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1916 "sql.y"
    { /* global xxx =  */
        if (0 == strncasecmp((yyvsp[(1) - (2)].strval), "global", 6)) {
            Item *i = calloc(1, sizeof(*i));
            i->token2 = GLOBAL;
            i->token1 = NAME;
            i->name = strdup((yyvsp[(2) - (2)].strval));
            free((yyvsp[(1) - (2)].strval));
            free((yyvsp[(2) - (2)].strval));
            
            (yyval.item) = i;
        } else if ( 0 == strncasecmp((yyvsp[(1) - (2)].strval), "session", 7)) {
            Item *i = calloc(1, sizeof(*i));
            i->token2 = SESSION;
            i->token1 = NAME;
            i->name = strdup((yyvsp[(2) - (2)].strval));
            free((yyvsp[(1) - (2)].strval));
            free((yyvsp[(2) - (2)].strval));
            
            (yyval.item) = i;
        } else {
            yyerror("show | set %s error ", (yyvsp[(1) - (2)].strval));
            (yyval.item) = NULL;
        }
    ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1939 "sql.y"
    { /* xxx = */
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NAME;
        i->name = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
            
        (yyval.item) = i;
    ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1946 "sql.y"
    { /* @xxx = */
        Item *i = calloc(1, sizeof(*i));
        i->token1 = USERVAR;
        i->name = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));

        (yyval.item) = i;
    ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1953 "sql.y"
    { /* global @xxx = */
        if (0 == strncasecmp((yyvsp[(1) - (2)].strval), "global", 6)) {
            Item *i = calloc(1, sizeof(*i));
            i->token2 = GLOBAL;
            i->token1 = USERVAR;
            i->name = strdup((yyvsp[(2) - (2)].strval));
            free((yyvsp[(1) - (2)].strval));
            free((yyvsp[(2) - (2)].strval));
            
            (yyval.item) = i;
        } else if ( 0 == strncasecmp((yyvsp[(1) - (2)].strval), "session", 7)) {
            Item *i = calloc(1, sizeof(*i));
            i->token2 = SESSION;
            i->token1 = USERVAR;
            i->name = strdup((yyvsp[(2) - (2)].strval));
            free((yyvsp[(1) - (2)].strval));
            free((yyvsp[(2) - (2)].strval));
            
            (yyval.item) = i;
        }
    ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1976 "sql.y"
    { debug ("STMT");;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1978 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(2) - (2)].strval));
        i->token1 = NAME;
        free((yyvsp[(2) - (2)].strval));
        curStmt->use = i;

        stmt->sql_command = SQLCOM_USE;
    ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1997 "sql.y"
    {debug("truncate");;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1999 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(2) - (2)].strval));
        i->token1 = NAME;
        free((yyvsp[(2) - (2)].strval));
        curStmt->desc = i;

        stmt->sql_command = SQLCOM_TRUNCATE;

    ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 2016 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->prefix = strdup((yyvsp[(2) - (4)].strval));
        i->name = strdup((yyvsp[(4) - (4)].strval));
        i->token1 = NAME;
        free((yyvsp[(2) - (4)].strval));
        free((yyvsp[(4) - (4)].strval));
        curStmt->desc = i;

        stmt->sql_command = SQLCOM_TRUNCATE;
    ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 2037 "sql.y"
    { debug("STMT");;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 2040 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(2) - (2)].strval));
        i->token1 = NAME;
        free((yyvsp[(2) - (2)].strval));
        curStmt->desc = i;

        stmt->sql_command = SQLCOM_SHOW_TABLES;
    ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 2056 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("desc From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(4) - (4)].strval));
        i->prefix = strdup((yyvsp[(2) - (4)].strval));
        i->token1 = NAME;
        free((yyvsp[(2) - (4)].strval));
        free((yyvsp[(4) - (4)].strval));
        curStmt->desc = i;

        stmt->sql_command = SQLCOM_SHOW_FIELDS;
    ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 2078 "sql.y"
    { debug("STMT"); ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 2082 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;
    ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 2093 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(1) - (1)].strval));
        free((yyvsp[(1) - (1)].strval));
        i->token1 = NAME;
        (yyval.item) = i;
    ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 2099 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup("DEFAULT");
        i->token1 = NAME;
        (yyval.item) = i;
    ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 2104 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup("NULL");
        i->token1 = NAME;
        (yyval.item) = i;
    ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 2111 "sql.y"
    {
        curStmt->sql_command = SQLCOM_SET_OPTION;
    ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 2113 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        curStmt->sql_command = SQLCOM_SET_OPTION;
        debug("SET NAMES ");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SETNAMES;
        i->name = strdup("NAMES");

        listAddNodeTail(curStmt->setList, i); 
        listAddNodeTail(curStmt->setList, (yyvsp[(2) - (2)].item)); 

        (yyval.intval)=0;
    ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 2132 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        curStmt->sql_command = SQLCOM_SET_OPTION;
        debug("SET LIST PASSWORD ");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SETPASSWORD;

        listAddNodeTail(curStmt->setList, i); 
        listAddNodeTail(curStmt->setList, (yyvsp[(4) - (4)].item)); 
        (yyval.intval) = 0;
    ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 2149 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        curStmt->sql_command = SQLCOM_SET_OPTION;
        debug("SET CHARACTER default ");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SETCHARACTER;
        i->name = strdup("character");

        listAddNodeTail(curStmt->setList, i); 
        listAddNodeTail(curStmt->setList, (yyvsp[(3) - (3)].item)); 
        (yyval.intval) = 1;
    ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 2167 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        curStmt->sql_command = SQLCOM_SET_OPTION;
        debug("SET OPTION ");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SETOPTION;
        i->name = strdup("OPTION"); 
        listAddNodeTail(curStmt->setList, i); 
        (yyval.intval) = 1;
    ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 2183 "sql.y"
    {
        Stmt *stmt = calloc(1, sizeof(*stmt));
        stmtInit(stmt);
        if (curStmt) {
            stmt->father = curStmt;
        }
        debug("set From %p to child %p", curStmt, stmt);
        curStmt = stmt;

        curStmt->sql_command = SQLCOM_SET_OPTION;
        debug("SETTRAN ");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SETOPTION;
        i->name = (yyvsp[(1) - (1)].strval); 
        listAddNodeTail(curStmt->setList, i); 
        (yyval.intval) = 1;
    ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 2201 "sql.y"
    {
        debug("SET LIST1 ");
        listAddNodeTail(curStmt->setList, (yyvsp[(1) - (1)].item)); 
        (yyval.intval) = 0;
    ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 2205 "sql.y"
    {
        debug("SET LIST2 ");
        listAddNodeTail(curStmt->setList, (yyvsp[(3) - (3)].item)); 
        (yyval.intval) = 1;
    ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 2212 "sql.y"
    {(yyval.item) = NULL;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 2212 "sql.y"
    {(yyval.item)= NULL;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 2214 "sql.y"
    {
        (yyval.item)= (yyvsp[(1) - (1)].item);
    ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 2216 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NAME;
        i->name = strdup("BINARY");
        (yyval.item) = i;
    ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 2221 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NAME;
        i->name = strdup("NULL");
        (yyval.item) = i;
    ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 2226 "sql.y"
    {
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NAME;
        i->name = strdup("DEFAULT");
        (yyval.item) = i;
    ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 2233 "sql.y"
    { if ((yyvsp[(2) - (3)].subtok) != 4) yyerror("bad set to @%s", (yyvsp[(2) - (3)].subtok));
        debug("SET expr ");

        Item *c = calloc(1, sizeof(*c));
        c->token1 = COMPARISON;
        c->token2 = (yyvsp[(2) - (3)].subtok);
        c->left = (yyvsp[(1) - (3)].item);
        c->right = (yyvsp[(3) - (3)].item);

        (yyval.item) = c;
    ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 2243 "sql.y"
    {
        debug("SET %s", (yyvsp[(3) - (3)].item));

        Item *c = calloc(1, sizeof(*c));
        c->token1 = ASSIGN;
        c->left = (yyvsp[(1) - (3)].item);
        c->right = (yyvsp[(3) - (3)].item);

        (yyval.item) = c;
    ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 2257 "sql.y"
    { debug("NAME %s", (yyvsp[(1) - (1)].strval));
            Item *i = calloc(1, sizeof(Item));
            i->name = strdup((yyvsp[(1) - (1)].strval));
            free((yyvsp[(1) - (1)].strval));
            i->token1 = NAME;
            (yyval.item) = i;
    ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 2264 "sql.y"
    { debug("USERVAR %s", (yyvsp[(1) - (1)].strval));
            Item *i = calloc(1, sizeof(*i));
            i->name = strdup((yyvsp[(1) - (1)].strval));
            free((yyvsp[(1) - (1)].strval));
            i->token1 = USERVAR;
            (yyval.item) = i;
       ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 2271 "sql.y"
    { debug("FIELDNAME %s.%s", (yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].strval)); 
            Item *i = calloc(1, sizeof(*i));
            i->prefix = strdup((yyvsp[(1) - (3)].strval));
            i->name = strdup((yyvsp[(3) - (3)].strval));
            free((yyvsp[(1) - (3)].strval));
            free((yyvsp[(3) - (3)].strval));
            i->token1 = NAME;
            (yyval.item) = i;
        ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 2280 "sql.y"
    { debug("STRING %s", (yyvsp[(1) - (1)].strval)); 
            Item *i = calloc(1, sizeof(*i));
            i->name = strdup((yyvsp[(1) - (1)].strval));
            free((yyvsp[(1) - (1)].strval));
            i->token1 = STRING;
            (yyval.item) = i;
        ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 2287 "sql.y"
    { debug("NUMBER %d", (yyvsp[(1) - (1)].intval)); 
            Item *i = calloc(1, sizeof(*i));
            i->intNum = (yyvsp[(1) - (1)].intval);
            i->token1 = INTNUM;
            (yyval.item) = i;
        ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 2293 "sql.y"
    { debug("FLOAT %g", (yyvsp[(1) - (1)].floatval)); 
            Item *i = calloc(1, sizeof(*i));
            i->doubleNum = (yyvsp[(1) - (1)].floatval);
            i->token1 = APPROXNUM;
            (yyval.item) = i;
        ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 2299 "sql.y"
    { debug("BOOL %d", (yyvsp[(1) - (1)].intval)); 
            Item *i = calloc(1, sizeof(*i));
            i->intNum = (yyvsp[(1) - (1)].intval);
            i->token1 = BOOL;
            (yyval.item) = i;
    ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 2306 "sql.y"
    { debug("ADD"); 
            Item *i = calloc(1, sizeof(*i));
            i->token1 = ADD_OP;
            i->left = (yyvsp[(1) - (3)].item);
            i->right = (yyvsp[(3) - (3)].item);
            (yyval.item) = i;
    ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 2312 "sql.y"
    { debug("INTERVAL ADD"); 
            Item *i = calloc(1, sizeof(*i));
            i->token1 = ADD_OP;
            i->left = (yyvsp[(1) - (3)].item);
            i->right = (yyvsp[(3) - (3)].item);
            (yyval.item) = i;
    ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 2318 "sql.y"
    { debug("INTERVAL SUB "); 
            Item *i = calloc(1, sizeof(*i));
            i->token1 = SUB_OP;
            i->left = (yyvsp[(1) - (3)].item);
            i->right = (yyvsp[(3) - (3)].item);
            (yyval.item) = i;
    ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 2324 "sql.y"
    { debug("INTERVAL ADD"); 
            Item *i = calloc(1, sizeof(*i));
            i->token1 = ADD_OP;
            i->left = (yyvsp[(1) - (3)].item);
            i->right = (yyvsp[(3) - (3)].item);
            (yyval.item) = i;
    ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 2330 "sql.y"
    { debug("SUB"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SUB_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 2336 "sql.y"
    { debug("MUL"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = MUL_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 2342 "sql.y"
    { debug("DIV"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = DIV_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 2348 "sql.y"
    { debug("MOD"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = MOD;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 2354 "sql.y"
    { debug("MOD"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = MOD;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 2360 "sql.y"
    { debug("NEG"); 
        /*TODO*/ 
        Item *i = calloc(1, sizeof(*i));
        i->left = (yyvsp[(2) - (2)].item);
        (yyval.item) = i;
   ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 2365 "sql.y"
    { debug("AND"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = ANDOP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 2371 "sql.y"
    { debug("OR"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = OR;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 2377 "sql.y"
    { debug("XOR"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = XOR;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 2383 "sql.y"
    { debug("CMP %d ", (yyvsp[(2) - (3)].subtok));
        Item *i = calloc(1, sizeof(*i));
        i->token1 = COMPARISON;
        i->token2 = (yyvsp[(2) - (3)].subtok);
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 2390 "sql.y"
    { debug("CMPSELECT %d", (yyvsp[(2) - (5)].subtok)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = COMPARISON;
        i->token2 = (yyvsp[(2) - (5)].subtok);
        i->left = (yyvsp[(1) - (5)].item);
        i->next = (yyvsp[(4) - (5)].stmt);
        (yyval.item) = i;
   ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 2397 "sql.y"
    { debug("CMPANYSELECT %d", (yyvsp[(2) - (6)].subtok)); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2400 "sql.y"
    { debug("CMPANYSELECT %d", (yyvsp[(2) - (6)].subtok)); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2401 "sql.y"
    { debug("CMPALLSELECT %d", (yyvsp[(2) - (6)].subtok)); ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2402 "sql.y"
    { debug("BITOR"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = BITOR_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2408 "sql.y"
    { debug("BITAND");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = BITAND_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2414 "sql.y"
    { debug("BITXOR"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = BITXOR_OP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2420 "sql.y"
    { debug("SHIFT %s", (yyvsp[(2) - (3)].subtok)==1?"left":"right"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = SHIFT;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2426 "sql.y"
    { debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NOT;
        i->left = (yyvsp[(2) - (2)].item);
        (yyval.item) = i;
   ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2431 "sql.y"
    { debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NOT;
        i->left = (yyvsp[(2) - (2)].item);
        (yyval.item) = i;
   ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2436 "sql.y"
    { debug("ASSIGN @%s", (yyvsp[(1) - (3)].strval)); free((yyvsp[(1) - (3)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = ASSIGN;
        i->name = strdup((yyvsp[(1) - (3)].strval));
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2442 "sql.y"
    {
        (yyval.item) = (yyvsp[(2) - (3)].item); 
   ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2447 "sql.y"
    { debug("ISNULL"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NULLX;
        i->left = (yyvsp[(1) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2453 "sql.y"
    { debug("ISNULL"); debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NULLX;
        i->token2 = NOT;
        i->left = (yyvsp[(1) - (4)].item);
        (yyval.item) = i;
   ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2460 "sql.y"
    {
        debug(" = NULL or != NULL");
        if (((yyvsp[(2) - (3)].subtok) != 4) && ((yyvsp[(2) - (3)].subtok) != 12 )) yyerror("bad nullx to %d", (yyvsp[(2) - (3)].subtok));
        /* only = and != */
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NULLX;
        i->token2 = (yyvsp[(2) - (3)].subtok);
        i->left = (yyvsp[(1) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2470 "sql.y"
    { debug("ISBOOL %d", (yyvsp[(3) - (3)].intval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = BOOL;
        i->left = (yyvsp[(1) - (3)].item);
        (yyval.item) = i;
   ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2476 "sql.y"
    { debug("ISBOOL %d", (yyvsp[(4) - (4)].intval)); debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NOT;
        i->token2 = BOOL;
        i->left = (yyvsp[(1) - (4)].item);
        (yyval.item) = i;
   ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2485 "sql.y"
    { debug("BETWEEN"); 
        /* TODO */
        Item *i = calloc(1, sizeof(*i));
        i->token1 = BETWEEN;
        i->token2 = BOOL;
        i->left = (yyvsp[(1) - (5)].item);
        (yyval.item) = i;
    ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2499 "sql.y"
    {
        debug("val_list:expr1 %p %s %d", (yyvsp[(1) - (1)].item), (yyvsp[(1) - (1)].item)->name, (yyvsp[(1) - (1)].item)->token1);
        list *val_list = listCreate();
        listAddNodeHead(val_list, (yyvsp[(1) - (1)].item));
        (yyval.listval) = val_list;
    ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2505 "sql.y"
    {
        debug("val_list:expr2 %p %s", (yyvsp[(1) - (3)].item), (yyvsp[(1) - (3)].item)->name); 
        listAddNodeHead((yyvsp[(3) - (3)].listval), (yyvsp[(1) - (3)].item));
        (yyval.listval) = (yyvsp[(3) - (3)].listval);
    ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2512 "sql.y"
    { (yyval.listval) = NULL; ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2516 "sql.y"
    { debug("ISIN %d", (yyvsp[(4) - (5)].listval)); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = IN;
        i->left = (yyvsp[(1) - (5)].item);
        i->right = (yyvsp[(4) - (5)].listval);
        (yyval.item) = i;
    ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2523 "sql.y"
    { debug("ISIN %d", (yyvsp[(5) - (6)].listval)); debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NOT;
        i->token2 = IN;
        i->left = (yyvsp[(1) - (6)].item);
        i->right = (yyvsp[(5) - (6)].listval);
        (yyval.item) = i;
   ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2531 "sql.y"
    { 
        debug("INSELECT From child %p to father %p", curStmt, curStmt->father); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = IN;
        i->token2 = SELECT;
        i->left = (yyvsp[(1) - (5)].item);
        i->right = (yyvsp[(4) - (5)].stmt);
        curStmt = curStmt->father;
        (yyval.item) = i;
   ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 2541 "sql.y"
    {
        debug("NOTINSELECT From child %p to father %p", curStmt, curStmt->father); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = NOT;
        i->token1 = SELECT;
        i->left = (yyvsp[(1) - (6)].item);
        i->right = (yyvsp[(5) - (6)].stmt);
        curStmt = curStmt->father;
        (yyval.item) = i;
   ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2551 "sql.y"
    { debug("EXISTS"); if((yyvsp[(1) - (4)].subtok)) debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = EXISTS;
        i->right = NULL;
        (yyval.item) = i;
   ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 2559 "sql.y"
    {
        debug("CALL %d %s", (yyvsp[(3) - (4)].listval), (yyvsp[(1) - (4)].strval)); 
        Item *i = calloc(1, sizeof(*i));
        i->name = strdup((yyvsp[(1) - (4)].strval));
        free((yyvsp[(1) - (4)].strval));
        i->token1 = NAME;
        i->right = (yyvsp[(3) - (4)].listval);
        (yyval.item) = i;
    ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 2572 "sql.y"
    { NORMAL_FUNCTION(FABS); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2573 "sql.y"
    { NORMAL_FUNCTION(FACOS); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2575 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FADDTIME); ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2577 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FAES_DECRYPT); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2579 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FAES_ENCRYPT); ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2580 "sql.y"
    { NORMAL_FUNCTION(FAREA); ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2581 "sql.y"
    { NORMAL_FUNCTION(FASBINARY); ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2582 "sql.y"
    { NORMAL_FUNCTION(FASIN); ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2583 "sql.y"
    { NORMAL_FUNCTION(FASTEXT); ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2584 "sql.y"
    { NORMAL_FUNCTION(FASWKB); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2585 "sql.y"
    { NORMAL_FUNCTION(FASWKT); ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2586 "sql.y"
    { NORMAL_FUNCTION(FATAN); ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2587 "sql.y"
    { NORMAL_FUNCTION(FATAN2); ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2588 "sql.y"
    { NORMAL_FUNCTION(FASCII); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2590 "sql.y"
    { NORMAL_FUNCTION(FAVG); ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2591 "sql.y"
    { NORMAL_FUNCTION_DISTINCT(FAVG); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2593 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FADDDATE); ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2595 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FBENCHMARK); ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2596 "sql.y"
    { NORMAL_FUNCTION(FBIN); ;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2597 "sql.y"
    { NORMAL_FUNCTION(FBIT_AND); ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2598 "sql.y"
    { NORMAL_FUNCTION(FBIT_OR); ;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2599 "sql.y"
    { NORMAL_FUNCTION(FBIT_XOR); ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2600 "sql.y"
    { NORMAL_FUNCTION(FBIT_COUNT); ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2601 "sql.y"
    { NORMAL_FUNCTION(FBIT_LENGTH); ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2603 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCAST); ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2604 "sql.y"
    { NORMAL_FUNCTION(FCEILING); ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2605 "sql.y"
    { NORMAL_FUNCTION(FCENTROID); ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2607 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCHAR); ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2608 "sql.y"
    { NORMAL_FUNCTION(FCHARACTER_LENGTH); ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2609 "sql.y"
    { NORMAL_FUNCTION(FCOERCIBILITY); ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2610 "sql.y"
    { NORMAL_FUNCTION(FCOMPRESS); ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2612 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCONCAT); ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2613 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCONCAT_WS); ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 2614 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCONNECTION_ID); ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 2616 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCONV); ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2618 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FCONVERT_TZ); ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2619 "sql.y"
    { NORMAL_FUNCTION(FCOS); ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 2620 "sql.y"
    { NORMAL_FUNCTION(FCOT); ;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 2621 "sql.y"
    { NORMAL_FUNCTION(FCRC32); ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 2622 "sql.y"
    { NORMAL_FUNCTION(FCROSSESS); ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 2624 "sql.y"
    { NORMAL_FUNCTION_DISTINCT(FCOUNT); ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2625 "sql.y"
    { NORMAL_FUNCTION_WILD(FCOUNT); ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2626 "sql.y"
    { NORMAL_FUNCTION_ONE_PARAM(FCOUNT); ;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2627 "sql.y"
    { NORMAL_FUNCTION(FCHARSET); ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2628 "sql.y"
    { NORMAL_FUNCTION(FCOLLATION); ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2629 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURRENT_USER); ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2630 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURDATE); ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2631 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURRENT_DATE); ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2632 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURRENT_TIMESTAMP); ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2633 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURTIME); ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2634 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FCURTIME_TIME); ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2635 "sql.y"
    { NORMAL_FUNCTION(FDATE); ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2637 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FDATEDIFF); ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2638 "sql.y"
    { NORMAL_FUNCTION(FDATENAME); ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2639 "sql.y"
    { NORMAL_FUNCTION(FDATEOFMONTH); ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2640 "sql.y"
    { NORMAL_FUNCTION(FDATEOFWEEK); ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2641 "sql.y"
    { NORMAL_FUNCTION(FDATEOFYEAR); ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2647 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FDATE_FORMAT); ;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 2648 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FDATABASE); ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 2649 "sql.y"
    { NORMAL_FUNCTION(FDAY); ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2650 "sql.y"
    { NORMAL_FUNCTION(FDAYNAME); ;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2651 "sql.y"
    { NORMAL_FUNCTION(FDAYOFMONTH); ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2652 "sql.y"
    { NORMAL_FUNCTION(FDAYOFWEEK); ;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 2653 "sql.y"
    { NORMAL_FUNCTION(FDAYOFYEAR); ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2654 "sql.y"
    { NORMAL_FUNCTION(FDEFAULT); ;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2655 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FDECODE); ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2656 "sql.y"
    { NORMAL_FUNCTION(FDEGREES); ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2658 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FDES_DECRYPT); ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2660 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FDES_ENCRYPT); ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2661 "sql.y"
    { NORMAL_FUNCTION(FDIMENSION); ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2662 "sql.y"
    { NORMAL_FUNCTION(FISJOINT); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2664 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FELT); ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2666 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FENCODE); ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2667 "sql.y"
    { NORMAL_FUNCTION(FENCRYPT); ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2668 "sql.y"
    { NORMAL_FUNCTION(FENDPOINT); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2669 "sql.y"
    { NORMAL_FUNCTION(FENVELOPE); ;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 2670 "sql.y"
    { NORMAL_FUNCTION(FEQUALS); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2671 "sql.y"
    { NORMAL_FUNCTION(FEXP); ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2673 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FEXPORT_SET); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2674 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FEXTRACT); ;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2675 "sql.y"
    { NORMAL_FUNCTION(FEXTERIORRING); ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2677 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FEXTRACTVALUE); ;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2679 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FFIELD); ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2681 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FFIND_IN_SET); ;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2682 "sql.y"
    { NORMAL_FUNCTION(FFLOOR); ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2684 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FFORMAT); ;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2685 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FFOUND_ROWS); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 2686 "sql.y"
    { NORMAL_FUNCTION(FFROM_DAYS); ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2687 "sql.y"
    { NORMAL_FUNCTION(FFROM_UNIXTIME); ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2689 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FGET_FORMAT); ;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2690 "sql.y"
    { NORMAL_FUNCTION(FGEOMCOLLFROMTEXT); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2691 "sql.y"
    { NORMAL_FUNCTION(FGEOMCOLLFROMWKB); ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2692 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYCOLLECTIONFROMTEXT); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2693 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYCOLLECTIONFROMWKB); ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2694 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYFROMTEXT); ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2695 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYFROMWKB); ;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2696 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYN); ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2697 "sql.y"
    { NORMAL_FUNCTION(FGEOMETRYTYPE); ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2698 "sql.y"
    { NORMAL_FUNCTION(FGEOMFROMTEXT); ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2699 "sql.y"
    { NORMAL_FUNCTION(FGEOMFROMWKB); ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2701 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FGET_LOCK); ;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2702 "sql.y"
    { NORMAL_FUNCTION(FGLENGTH); ;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2703 "sql.y"
    { NORMAL_FUNCTION(FGREATEST); ;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2704 "sql.y"
    { NORMAL_FUNCTION(FHEX); ;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2705 "sql.y"
    { NORMAL_FUNCTION(FHOUR); ;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2707 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FINSERT); ;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2709 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FINSTR); ;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2711 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FIFNULL); ;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2712 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FIF); ;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2713 "sql.y"
    { NORMAL_FUNCTION(FINET_ATON); ;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2714 "sql.y"
    { NORMAL_FUNCTION(FINET_NTOA); ;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2715 "sql.y"
    { NORMAL_FUNCTION(FINTERIORRINGN); ;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2716 "sql.y"
    { NORMAL_FUNCTION(FINTERSECTS); ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2717 "sql.y"
    { NORMAL_FUNCTION(FISCLOSED); ;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2718 "sql.y"
    { NORMAL_FUNCTION(FISEMPTY); ;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2719 "sql.y"
    { NORMAL_FUNCTION(FISNULL); ;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2720 "sql.y"
    { NORMAL_FUNCTION(FISSIMPLE); ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2721 "sql.y"
    { NORMAL_FUNCTION(FIS_FREE_LOCK); ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2722 "sql.y"
    { NORMAL_FUNCTION(FIS_USED_LOCK); ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2723 "sql.y"
    { NORMAL_FUNCTION(FLAST_DAY); ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2724 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FLAST_INSERT_ID); ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2725 "sql.y"
    { NORMAL_FUNCTION(FLAST_INSERT_ID); ;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2726 "sql.y"
    { NORMAL_FUNCTION(FLCASE); ;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2728 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FLEFT); ;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2729 "sql.y"
    { NORMAL_FUNCTION(FLENGTH); ;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2730 "sql.y"
    { NORMAL_FUNCTION(FLINEFROMTEXT); ;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2731 "sql.y"
    { NORMAL_FUNCTION(FLINEFROMWKB); ;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2732 "sql.y"
    { NORMAL_FUNCTION(FLINESTRINGFROMTEXT); ;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2733 "sql.y"
    { NORMAL_FUNCTION(FLINESTRINGFROMWKB); ;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2734 "sql.y"
    { NORMAL_FUNCTION(FLN); ;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2735 "sql.y"
    { NORMAL_FUNCTION(FLOAD_FILE); ;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2737 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FLOCATE); ;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2738 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FLOG); ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2739 "sql.y"
    { NORMAL_FUNCTION(FLOG10); ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2740 "sql.y"
    { NORMAL_FUNCTION(FLOG2); ;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2741 "sql.y"
    { NORMAL_FUNCTION(FLOWER); ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2743 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FLPAD); ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2744 "sql.y"
    { NORMAL_FUNCTION(FLTRIM); ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2745 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FLOCALTIME); ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2746 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FLOCALTIMESTAMP); ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2748 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FMAKEDATE); ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2749 "sql.y"
    { NORMAL_FUNCTION(FMAKETIME); ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2751 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FMAKE_SET); ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2753 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FMASTER_POS_WAIT); ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2754 "sql.y"
    { NORMAL_FUNCTION(FMBRCONTAINS); ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2755 "sql.y"
    { NORMAL_FUNCTION(FMBRDISJOINT); ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2756 "sql.y"
    { NORMAL_FUNCTION(FMBREQUAL); ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2757 "sql.y"
    { NORMAL_FUNCTION(FMBRINTERSECTS); ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2758 "sql.y"
    { NORMAL_FUNCTION(FMBROVERLAPS); ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2759 "sql.y"
    { NORMAL_FUNCTION(FMBRTOUCHES); ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2760 "sql.y"
    { NORMAL_FUNCTION(FMBRWITHIN); ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2761 "sql.y"
    { NORMAL_FUNCTION(FMD5); ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2762 "sql.y"
    { NORMAL_FUNCTION(FMLINEFROMTEXT); ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2763 "sql.y"
    { NORMAL_FUNCTION(FMLINEFROMWKB); ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2764 "sql.y"
    { NORMAL_FUNCTION(FMONTHNAME); ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2765 "sql.y"
    { NORMAL_FUNCTION(FMPOINTFROMTEXT); ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2766 "sql.y"
    { NORMAL_FUNCTION(FMPOINTFROMWKB); ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2767 "sql.y"
    { NORMAL_FUNCTION(FMPOLYFROMTEXT); ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2768 "sql.y"
    { NORMAL_FUNCTION(FMPOLYFROMWKB); ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2769 "sql.y"
    { NORMAL_FUNCTION(FMULTILINESTRINGFROMTEXT); ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2770 "sql.y"
    { NORMAL_FUNCTION(FMULTILINESTRINGFROMWKB); ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2771 "sql.y"
    { NORMAL_FUNCTION(FMULTIPOINTFROMTEXT); ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2772 "sql.y"
    { NORMAL_FUNCTION(FMULTIPOINTFROMWKB); ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2773 "sql.y"
    { NORMAL_FUNCTION(FMULTIPOLYGONFROMTEXT); ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2774 "sql.y"
    { NORMAL_FUNCTION(FMULTIPOLYGONFROMWKB); ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2775 "sql.y"
    { NORMAL_FUNCTION(FMICROSECOND); ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2776 "sql.y"
    { NORMAL_FUNCTION(FMINUTE); ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2777 "sql.y"
    { NORMAL_FUNCTION(FMONTH); ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2779 "sql.y"
    { NORMAL_FUNCTION(FGROUP_CONCAT); ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2780 "sql.y"
    { NORMAL_FUNCTION(FAGAINST); ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2781 "sql.y"
    { NORMAL_FUNCTION(FMATCH); ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2782 "sql.y"
    { NORMAL_FUNCTION(FMAX); ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2784 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FMID); ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2785 "sql.y"
    { NORMAL_FUNCTION(FMIN); ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2787 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FMOD); ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2788 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FNOW); ;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2789 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FNAME_CONST); ;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2790 "sql.y"
    { NORMAL_FUNCTION(FNULLIF); ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2791 "sql.y"
    { NORMAL_FUNCTION(FNUMGEOMETRIES); ;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2792 "sql.y"
    { NORMAL_FUNCTION(FNUMINTERIORRINGS); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2793 "sql.y"
    { NORMAL_FUNCTION(FNUMPOINTS); ;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2794 "sql.y"
    { NORMAL_FUNCTION(FOCT); ;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2795 "sql.y"
    { NORMAL_FUNCTION(FOCTET_LENGTH); ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2796 "sql.y"
    { NORMAL_FUNCTION(FORD); ;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2797 "sql.y"
    { NORMAL_FUNCTION(FOVERLAPS); ;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2798 "sql.y"
    { NORMAL_FUNCTION(FOLD_PASSWORD); ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2800 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FPERIOD_ADD); ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2802 "sql.y"
    { NORMAL_FUNCTION(FPERIOD_DIFF); ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2803 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FPI); ;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2804 "sql.y"
    { NORMAL_FUNCTION(FPASSWORD); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2805 "sql.y"
    { NORMAL_FUNCTION(FPOINTFROMTEXT); ;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2806 "sql.y"
    { NORMAL_FUNCTION(FPOINTFROMWKB); ;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2807 "sql.y"
    { NORMAL_FUNCTION(FPOINTN); ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2808 "sql.y"
    { NORMAL_FUNCTION(FPOLYFROMTEXT); ;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2809 "sql.y"
    { NORMAL_FUNCTION(FPOLYFROMWKB); ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2810 "sql.y"
    { NORMAL_FUNCTION(FPOLYGONFROMTEXT); ;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2811 "sql.y"
    { NORMAL_FUNCTION(FPOLYGONFROMWKB); ;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2813 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FPOWER); ;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2814 "sql.y"
    { NORMAL_FUNCTION(FQUARTER); ;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2815 "sql.y"
    { NORMAL_FUNCTION(FQUOTE); ;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2816 "sql.y"
    { NORMAL_FUNCTION(FRADIANS); ;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2817 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FRAND); ;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2818 "sql.y"
    { NORMAL_FUNCTION(FRAND); ;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2819 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FROUND); ;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2820 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FROW_COUNT); ;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2822 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FREPEAT); ;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2824 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FREPLACE); ;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2825 "sql.y"
    { NORMAL_FUNCTION(FREVERSE); ;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2827 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FRIGHT); ;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2829 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FRPAD); ;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2830 "sql.y"
    { NORMAL_FUNCTION(FRTRIM); ;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2831 "sql.y"
    { NORMAL_FUNCTION(FRELEASE_LOCK); ;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 2832 "sql.y"
    { NORMAL_FUNCTION(FSEC_TO_TIME); ;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 2833 "sql.y"
    { NORMAL_FUNCTION(FSEC_TO_DATE); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 2834 "sql.y"
    { NORMAL_FUNCTION(FSHA); ;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 2835 "sql.y"
    { NORMAL_FUNCTION(FSHA1); ;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 2836 "sql.y"
    { NORMAL_FUNCTION(FSIGN); ;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 2837 "sql.y"
    { NORMAL_FUNCTION(FSIN); ;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 2838 "sql.y"
    { NORMAL_FUNCTION(FSLEEP); ;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 2839 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FSCHEMA); ;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 2840 "sql.y"
    { NORMAL_FUNCTION(FSOUNDEX); ;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 2841 "sql.y"
    { NORMAL_FUNCTION(FSPACE); ;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 2842 "sql.y"
    { NORMAL_FUNCTION(FSQRT); ;}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 2843 "sql.y"
    { NORMAL_FUNCTION(FSRID); ;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 2844 "sql.y"
    { NORMAL_FUNCTION(FSTARTPOINT); ;}
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 2846 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSTRCMP); ;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 2848 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSTR_TO_DATE); ;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 2849 "sql.y"
    { NORMAL_FUNCTION(FSECOND); ;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 2851 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSUBTIME); ;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 2853 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSUBSTRING); ;}
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 2855 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSUBSTRING_INDEX); ;}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 2856 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FSESSION_USER); ;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 2857 "sql.y"
    { NORMAL_FUNCTION(FSTD); ;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 2858 "sql.y"
    { NORMAL_FUNCTION(FSTDDEV); ;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 2859 "sql.y"
    { NORMAL_FUNCTION(FSTDDEV_POP); ;}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 2860 "sql.y"
    { NORMAL_FUNCTION(FSTDDEV_SAMP); ;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 2862 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FSUBDATE); ;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 2863 "sql.y"
    { NORMAL_FUNCTION(FSUM); ;}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 2864 "sql.y"
    { NORMAL_FUNCTION_DISTINCT(FSUM); ;}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 2865 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FSYSDATE); ;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 2866 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FSYSTEM_USER); ;}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 2867 "sql.y"
    { NORMAL_FUNCTION(FTAN); ;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 2869 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTIMEDIFF); ;}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 2871 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTIME_FORMAT); ;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 2872 "sql.y"
    { NORMAL_FUNCTION(FTIME_TO_SEC); ;}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 2874 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTRUNCATE); ;}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 2875 "sql.y"
    { NORMAL_FUNCTION(FTOUCHES); ;}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 2876 "sql.y"
    { NORMAL_FUNCTION(FTO_DAYS); ;}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 2878 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTRIM); ;}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 2879 "sql.y"
    { NORMAL_FUNCTION(FTIME); ;}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 2881 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTIMESTAMP); ;}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 2883 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTIMESTAMPADD); ;}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 2885 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FTIMESTAMPDIFF); ;}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 2886 "sql.y"
    { NORMAL_FUNCTION(FVARIANCE); ;}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 2887 "sql.y"
    { NORMAL_FUNCTION(FVAR_POP); ;}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 2888 "sql.y"
    { NORMAL_FUNCTION(FVAR_SAMP); ;}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 2889 "sql.y"
    { NORMAL_FUNCTION(FUCASE); ;}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 2890 "sql.y"
    { NORMAL_FUNCTION(FUNCOMPRESS); ;}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 2891 "sql.y"
    { NORMAL_FUNCTION(FUNCOMPRESSED_LENGTH); ;}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 2892 "sql.y"
    { NORMAL_FUNCTION(FUNHEX); ;}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 2893 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUSER); ;}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 2894 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUNIX_TIMESTAMP); ;}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 2895 "sql.y"
    { NORMAL_FUNCTION(FUNIX_TIMESTAMP); ;}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 2897 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FUPDATEXML); ;}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 2898 "sql.y"
    { NORMAL_FUNCTION(FUPPER); ;}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 2899 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUUID); ;}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 2900 "sql.y"
    { NORMAL_FUNCTION(FUUID_SHORT); ;}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 2901 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FVERSION); ;}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 2902 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUTC_DATE); ;}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 2903 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUTC_TIME); ;}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 2904 "sql.y"
    { NORMAL_FUNCTION_NO_PARAM(FUTC_TIMESTAMP); ;}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 2906 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FWEEK); ;}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 2907 "sql.y"
    { NORMAL_FUNCTION(FWEEKDAY); ;}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 2908 "sql.y"
    { NORMAL_FUNCTION(FWEEKOFYEAR); ;}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 2909 "sql.y"
    { NORMAL_FUNCTION(FYEAR); ;}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 2911 "sql.y"
    { NORMAL_FUNCTION_ANY_PARAM(FYEARWEEK); ;}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 2912 "sql.y"
    { NORMAL_FUNCTION(FX); ;}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 2913 "sql.y"
    { NORMAL_FUNCTION(FY); ;}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 2916 "sql.y"
    {  debug("CALL 2 SUBSTR"); ;}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 2917 "sql.y"
    {  debug("CALL 3 SUBSTR"); ;}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 2918 "sql.y"
    { debug("CALL 3 TRIM"); ;}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 2920 "sql.y"
    { debug("CALL 2 FPOSITION"); ;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 2923 "sql.y"
    { debug("INT 1"); ;}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 2924 "sql.y"
    { debug("INT 2"); ;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 2925 "sql.y"
    { debug("INT 3"); ;}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 2928 "sql.y"
    {
        debug("CALL 3 DATE_ADD"); 
        list *l = listCreate();
        listAddNodeTail(l, (yyvsp[(3) - (6)].item));
        listAddNodeTail(l, (yyvsp[(5) - (6)].item));

        Item *i = calloc(1, sizeof(*i));
        i->token1 = FDATE_ADD;
        i->right = l;
        (yyval.item) = i;
    ;}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 2939 "sql.y"
    {
        debug("CALL 3 DATE_SUB");
        list *l = listCreate();
        listAddNodeTail(l, (yyvsp[(3) - (6)].item));
        listAddNodeTail(l, (yyvsp[(5) - (6)].item));

        Item *i = calloc(1, sizeof(*i));
        i->token1 = FDATE_SUB;
        i->right = l;
        (yyval.item) = i;
    ;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 2951 "sql.y"
    {
        debug("INTERVAL %s DAY_HOUR", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = DAY_HOUR;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 2958 "sql.y"
    {
        debug("INTERVAL %s DAY_MICROSECOND", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = DAY_MICROSECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 2965 "sql.y"
    {
        debug("INTERVAL %s DAY_MINUTE", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = DAY_MINUTE;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 2972 "sql.y"
    {
        debug("INTERVAL %s DAY_SECOND", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = DAY_SECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 2979 "sql.y"
    {
        debug("INTERVAL %s YEAR_MONTH", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = YEAR_MONTH;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 2986 "sql.y"
    {
        /* DAY not keyword*/
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->left = (yyvsp[(2) - (3)].item);

        if ((strcasecmp((yyvsp[(3) - (3)].strval), "day")) == 0) {
            debug("INTERVAL %d day", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = DAY;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "week")) == 0) {
            debug("INTERVAL %d day", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = WEEK;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "month")) == 0) {
            debug("INTERVAL %d month", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = MONTH;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "quarter")) == 0) {
            debug("INTERVAL %d quarter", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = QUARTER;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "year")) == 0) {
            debug("INTERVAL %d year", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = YEAR;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "microsecond")) == 0) {
            debug("INTERVAL %d day", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = MICROSECOND;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "second")) == 0) {
            debug("INTERVAL %d month", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = SECOND;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "minute")) == 0) {
            debug("INTERVAL %d quarter", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = MINUTE;
            (yyval.item) = i;
        } else if ((strcasecmp((yyvsp[(3) - (3)].strval), "hour")) == 0) {
            debug("INTERVAL %d year", (yyvsp[(2) - (3)].item)->intNum);
            i->token2 = HOUR;
            (yyval.item) = i;
        } else {
            yyerror("interval error %s", (yyvsp[(3) - (3)].strval));
            free((yyvsp[(2) - (3)].item));
            free(i);
        }
    ;}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3033 "sql.y"
    {
        debug("INTERVAL %s HOUR_MICROSECOND", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = HOUR_MICROSECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3040 "sql.y"
    {
        debug("INTERVAL %s HOUR_MINUTE", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = HOUR_MINUTE;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3047 "sql.y"
    {
        debug("INTERVAL %s HOUR_SECOND", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = HOUR_SECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3054 "sql.y"
    {
        debug("INTERVAL %s SECOND_MICROSECOND ", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = SECOND_MICROSECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3061 "sql.y"
    {
        debug("INTERVAL %s MINUTE_MICROSECOND ", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = MINUTE_MICROSECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3068 "sql.y"
    {
        debug("INTERVAL %s MINUTE_SECOND ", (yyvsp[(2) - (3)].item)->name);
        Item *i = calloc(1, sizeof(*i));
        i->token1 = INTERVAL;
        i->token2 = MINUTE_SECOND;
        i->left = (yyvsp[(2) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3077 "sql.y"
    {
    debug("CASE");
    Item *c = calloc(1, sizeof(*c));
    c->token1 = CASE;
    c->left = (yyvsp[(2) - (4)].item);
    c->next = (yyvsp[(3) - (4)].listval);
    (yyval.item) = c;

    ;}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3085 "sql.y"
    {
    debug("CASE ELSE");
    Item *c = calloc(1, sizeof(*c));
    c->token1 = CASE;
    c->token2 = ELSE;
    c->left = (yyvsp[(2) - (6)].item);
    c->right = (yyvsp[(5) - (6)].item);
    c->next = (yyvsp[(3) - (6)].listval);
    (yyval.item) = c;

    ;}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3095 "sql.y"
    {
    debug("CASE ");
    Item *c = calloc(1, sizeof(*c));
    c->token1 = CASE;
    c->next = (yyvsp[(2) - (3)].listval);
    (yyval.item) = c;
    
    ;}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3102 "sql.y"
    {
    debug("CASE ELSE");
    Item *c = calloc(1, sizeof(*c));
    c->token1 = CASE;
    c->token2 = ELSE;
    c->right = (yyvsp[(4) - (5)].item);
    c->next = (yyvsp[(2) - (5)].listval);
    (yyval.item) = c;

    ;}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3113 "sql.y"
    {
        debug("WHEN THEN ");

        Item *then = calloc(1, sizeof(*then));
        then->token1 = THEN;
        then->left = (yyvsp[(4) - (4)].item);

        Item *i= calloc(1, sizeof(*i));
        i->token1 = WHEN;
        i->left = (yyvsp[(2) - (4)].item);

        list *l = listCreate();
        listAddNodeTail(l, i);
        listAddNodeTail(l, then);
        (yyval.listval) = l;
    ;}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3128 "sql.y"
    {
        debug("WHEN THEN ");

        Item *then = calloc(1, sizeof(*then));
        then->token1 = THEN;
        then->left = (yyvsp[(3) - (5)].item);

        Item *i= calloc(1, sizeof(*i));
        i->token1 = WHEN;
        i->left = (yyvsp[(5) - (5)].item);

        listAddNodeTail((yyvsp[(1) - (5)].listval), i);
        listAddNodeTail((yyvsp[(1) - (5)].listval), then);
        (yyval.listval) = (yyvsp[(1) - (5)].listval);
    ;}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3144 "sql.y"
    { 
        debug("LIKE");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = LIKE;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3152 "sql.y"
    { 
        debug("LIKE"); debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = LIKE;
        i->token2 = NOT;
        i->left = (yyvsp[(1) - (4)].item);
        i->right = (yyvsp[(4) - (4)].item);
        (yyval.item) = i;
    ;}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3162 "sql.y"
    {
        debug("REGEXP");
        Item *i = calloc(1, sizeof(*i));
        i->token1 = REGEXP;
        i->left = (yyvsp[(1) - (3)].item);
        i->right = (yyvsp[(3) - (3)].item);
        (yyval.item) = i;
    ;}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3170 "sql.y"
    { 
        debug("REGEXP"); debug("NOT"); 
        Item *i = calloc(1, sizeof(*i));
        i->token1 = REGEXP;
        i->token2 = NOT;
        i->left = (yyvsp[(1) - (4)].item);
        i->right = (yyvsp[(4) - (4)].item);
        (yyval.item) = i;
    ;}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3180 "sql.y"
    { debug("STRTOBIN"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 10902 "sql.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 3183 "sql.y"


void debug(char *s, ...) {
    va_list ap;
    va_start(ap, s);

    //printf("rpn: ");
    //vfprintf(stdout, s, ap);
    //printf("\n");
    
}

void yyerror(char *s, ...)
{
    //AMB
    extern yylineno;

    va_list ap;
    va_start(ap, s);
    //assert(NULL);
    //AMB
    fprintf(stderr, "error in line %d with %s\n", yylineno,s);
    fprintf(stderr, "error: ");
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");

}


