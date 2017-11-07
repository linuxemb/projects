#projects
<<<<<<< HEAD
# autoconf
=======
Autotools--A pratictitioner's guide to GNU autoconf, automake and LibTool

<<< MAKE>>>>>


A Serperae Shell for each command.
cant export  a shell variable in one command and try toa ccess its value in the next . must do this--- string commands  in same line with ";"  Thus make passes the set of concaternatd commands as one command line to same shell. 

use  "\" at the end to avoid long line ---Wrap them

Dependencies ----  are objs taht provide suce material for targers, so Dependencies are essentially prereuisties of the targets. and should beupdated 1st


Make utility ---- rule-based command engine, and rules at work indicate which commands should be executed and when.   (

TAB---command ----- execute the sfollwoig statements from a shell accouding teo preceding rule.
---------------------the existane and time satmp of files mentioned in the rules indicate whehter the commands should executed in what order.

---
Directed graph--- A web of dependcy chains

$MAKE --- var   the val is command line withe optins to invoke current make process

Make -e ----- reverse this default behavior sothat var defined within env overide those defined with in the make file BUT not good to rely on env

$$(my_var)=--- escape he $ sign by doubleing it.... tell make not to interate the var reference but rather to treat it as literal text in the command

Make processes a makefile in 2 passes

1) ----- Gathers var and rules into tables and internal structures

2) ------It resolves dependencies deined by the rules. invoking those rules as neessary to rebuild the dependencies based on file system timestamps.

 if(newer)  then update dependencies

=========================
a seperate Shell for each command

---Variable binding ---  Since commands are processed at a later stage than rules, var references in commands are bound later than those in rules.
---Var references found in rules are expeanded when make builds the directed graph from the rules in the makefile. Thus,  a var rferencesd in a rule must be fullly define din a makefile before the referencing rule.


---Always assign a varible just before you intend to use it.



$@ --- full target name of curretn target / archieve file name part of li--both implcit and expicit rule


$%--- a member of an arcieve and is valid only when the current target is an archieve member....both
$?--- list of dependencies newer than current target. ...both

$<--- memeber of dependency list whose existence alloewed the rule to be chosen for taget----- ONLY implicit

$*---- currrent target name wiht suffix deleted, --- only implicit


==== GNU extension are not prtable,  ---better only use $@
.PHONE----- dot rule... or idrective... certain target dont generate filesystem object.


==================steps
mto@ubuntu:~/make/projects/gitjupiter/projects/jupiter$ cat steps.txt 
vi configure.ac
autoreconf -v
ls -lp
./configure
mv Makefile Makefile.in 
 mv src/Makefile src/Makefile.in



#################  Adding realy functinility #######

// modify Makefile.in and src/Makefile.in 


add Prefix-specifc substution var ... and  define package.. version... in
src/Makefile.in   ====> can launch make in src folder
Adding VPATH 
mkdir build
../configure
autogen.sh
autogen.sh
-------generated config.h.in and install-sh 2 files

autogen.sh

--------

#!/bin/sh
autoreconf --install
automake --add-missing --copy >/dev/null 2>&1


autoconf
./configure
./config.status config.h
./config.status --help 
./configure.status --file=extra:extra.in

>>>>>>> 8a5bab2af4d1316a6b7645d267015c656d3a3405
