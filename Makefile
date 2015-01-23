
RELEASE_TARGET=Baptiste_Fontaine_TP$(TPNUM)
TPDIR=TP$(TPNUM)

TGZ=$(TPDIR)/$(RELEASE_TARGET).tgz

ASSIGN_NUM=$(shell echo 1+$(TPNUM) | bc)

# this changes depending on the platform. On OSX it's `-i ''`, but on some it's
# `-i''` or `-i`
SED_I=sed -i ''

.default: help

help:
	@# Print this help
	@grep -A1 '^[a-z_]\+:' Makefile | sed s/:.*// | sed 's/@# //' \
		| grep -v '^--$$'

ensure_tpnum_0:
	@if [ -z "$(TPNUM)" ]; then echo "Set TPNUM!"; exit 1; fi

release: ensure_tpnum_0
	@# build the .tgz of $(TPNUM)
	rm -rf $(TPDIR)/$(RELEASE_TARGET)
	rm -rf $(TGZ)
	make -C $(TPDIR)/rendu/src clean
	cp -r $(TPDIR)/rendu $(TPDIR)/$(RELEASE_TARGET)
	cd $(TPDIR) && tar csvf $(TGZ) $(RELEASE_TARGET)
	@echo "now run 'scp $(TPDIR)/$(RELEASE_TARGET) lu:'"

new_tp: ensure_tpnum_0
	@# create a new TP$(TPNUM) directory from the skeleton
	@if [ -z "$(TPNUM)" ]; then echo "Set TPNUM!"; exit 1; fi
	cp -r skeleton $(TPDIR)
	find $(TPDIR) -type f | xargs $(SED_I) 's/%TPNUM%/$(TPNUM)/g'

push: ensure_tpnum_0
	@# push TP$(TPNUM) to DidEL
	echo TODO post on Didel
	@#didel assignments:submit M2T1SYSTAV $(TPNUM) "TP $(TPNUM)" $(TGZ)
