bin_PROGRAMS = rcs

rcs_SOURCES = ci.c co.c ident.c merge.c rcsclean.c rcsdiff.c rcsmerge.c \
		  rcsprog.c rlog.c rcsutil.c buf.c date.y diff.c diff3.c \
		  rcs.c rcsnum.c rcstime.c worklist.c xmalloc.c

INCLUDES = -I$(top_srcdir)/openbsd-compat/

LIBCOMPAT=$(top_srcdir)/openbsd-compat/.libs/libopenbsd-compat.a

LDADD = $(LIBCOMPAT)

#ci co ident merge rcsclean rcsdiff rcsmerge rlog
install-exec-hook:
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/ci$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/co$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/ident$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/merge$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/rcsclean$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/rcsdiff$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/rcsmerge$(EXEEXT)
	ln $(DESTDIR)$(bindir)/rcs$(EXEEXT) \
		$(DESTDIR)$(bindir)/rlog$(EXEEXT)
