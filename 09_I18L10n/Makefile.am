bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

ru/LC_MESSAGES/guess.mo: guess_ru.po
		mkdir -p `dirname $@`
		msgfmt $< -o $@

guess_ru.po:	tmp.pot
		msgmerge -U $@ $<

tmp.pot:	guess.pot guess.c
		xgettext -ktr -c guess.c -o guess.new.pot
		cp guess.pot tmp.pot
		msgmerge -U tmp.pot guess.new.pot

gitclean:	maintainer-clean
		git clean -fd