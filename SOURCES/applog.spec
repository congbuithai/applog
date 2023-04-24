Name:       applog
Version:    1
Release:    5
Summary:    Most simple RPM package
License:    FIXME
%description
This is my first RPM package, which does nothing

%prep
# we have no source, so nothing here

%build
%install
mkdir -p %{buildroot}/usr/local/bin/
mkdir -p %{buildroot}/etc/systemd/system/
install -m 755 applog %{buildroot}/usr/local/bin/applog
install -m 755 applogw %{buildroot}/usr/local/bin/applogw
install -m 444 applog@.service %{buildroot}/etc/systemd/system/applog@.service



%files
/usr/local/bin/applog
/usr/local/bin/applogw
/etc/systemd/system/applog@.service


%changelog
# let's skip this for now

