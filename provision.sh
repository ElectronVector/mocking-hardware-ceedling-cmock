#!/bin/bash

# This is the provisioning script which is executed when the virtual machine is first created.
# Here is where we install all of the dependencies for our project.

# Update our package repositories.
apt-get update

# Rake is a dependency for projects built with Ceedling.
apt-get -y install rake

# Create a script in /etc/profile.d which will automatically be run upon login.
# We'll set our path and any other environment variables here.
SETUP_SCRIPT=/etc/profile.d/setup-environment.sh

# Have the script start us in the host-shared folder.
echo "cd /vagrant" > $SETUP_SCRIPT
