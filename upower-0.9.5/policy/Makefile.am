polkit_policydir = $(datadir)/polkit-1/actions
polkit_policy_DATA =					\
	org.freedesktop.upower.policy		\
	org.freedesktop.upower.qos.policy

# You will need a recent intltool or the patch from this bug
# http://bugzilla.gnome.org/show_bug.cgi?id=462312
@INTLTOOL_POLICY_RULE@

EXTRA_DIST =						\
	org.freedesktop.upower.policy.in	\
	org.freedesktop.upower.qos.policy.in

DISTCLEANFILES =					\
	org.freedesktop.upower.policy		\
	org.freedesktop.upower.qos.policy

clean-local :
	rm -f *~

