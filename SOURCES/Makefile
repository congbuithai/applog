build:
	@mkdir -p ../BUILD
	@cp applog@.service ../BUILD/applog@.service
	@gcc applogw.c -o ../BUILD/applogw
	@gcc applog.c -o ../BUILD/applog
	@rpmbuild --define "_topdir `pwd`/../" -v -ba applog.spec

	# rpmbuild -bb applog.spec \
	# --buildroot=$(PWD) --clean
	# # --define='_topdir $(PWD)/../' 
	# # _rpmfilename "ApplogRpm"'
	# # --define='_builddir $(CURDIR)' \
	# # --define='_rpmdir $(CURDIR)' \
	# # --define='_rpmfilename "ApplogRpm"' \
	
clean:
	-rm -rf ../BUILD
	-rm -rf ../BUILDROOT
	-rm -rf ../RPMS
	-rm -rf ../SRPMS
	-rm -rf ../SPECS

rmsystemctl:
	rm -rf /etc/systemd/system/applog@.service
	rm -rf /usr/local/bin/applogw
	rm -rf /usr/local/bin/applog
	# yum remove applog -y

app:
	cp applog@.service /etc/systemd/system/applog@.service
	gcc applogw.c -o /usr/local/bin/applogw
	gcc applog.c -o /usr/local/bin/applog