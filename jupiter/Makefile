
# To avoid dist wont cp issue. create a phone target, fot force make to reuild it every time we make the dist target.
#FORCE:   #exected everytime for it is a phone targe

# Makefile.  Generated from Makefile.in by configure.
 
#package-specific substitution variable

 package 	=Jupiter
 version	= 1.0
 tarname = jupiter
 distdir = $(tarname)-$(version)
 
 # Prefix-specif substitution var
 prifix = /usr/local
 exec_prefix= ${prefix}
 bindir = ${exec_prefix}/bin
####################################### 
package = jupiter
version = 1.0
tarname =$(package)
distdir = $(tarname)-$(version)


prefix=/usr/local
export prefix

all clean check install jupiter:
	cd src && $(MAKE) $@
.PHONE: all clean


dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

# VPATH specific substitution variables
srcdir 		 = .


$(distdir): FORCE    #FORCE is a dependency to distdir 
	mkdir -p $(distdir)/src
# VPATH related
	cp $(srcdir)/configure.ac  $(distdir)
	cp $(srcdir)/configure  $(distdir)
	cp $(srcdir)/Makefile.in  $(distdir)
	cp $(srcdir)/src/Makefile.in $(distdir)/src
	cp $(srcdir)/src/main.c $(distdir)/src

#	cp Makefile $(distdir)
#	cp src/Makefile $(distdir)/src
#	cp src/main.c $(distdir)/src
FORCE:
	-rm $(distdir).tar.gz  > /dev/null 2>&1
	-rm -rf $(distdir) > /dev/null 2>&1


distcheck: $(distdir).tar.gz
	gzip -cd $(distdir).tar.gz | tar xvf -
	cd $(distdir) && $(MAKE) ./configure 
	cd $(distdir) && $(MAKE) all
	cd $(distdir) && $(MAKE) check 
	
#	rm -rf $(distdir)
	@echo "**** $(distdir).tar.gz is ready for distribution."

Makefile: Makefile.in config.status
	./config.status $@

config.status:configure
	./configure.status --recheck

.PHONE: FORCE  all clean  dist distcheck   
