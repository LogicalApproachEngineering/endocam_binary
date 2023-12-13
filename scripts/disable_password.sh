#! /bin/bash

# Original commands:
# sudo echo -e 'lae ALL=(ALL) ALL' >> /etc/sudoers
# sudo echo -e 'lae ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers

visudo="/etc/sudoers"
permission1="lae ALL=(ALL) ALL"
permission2="lae ALL=(ALL) NOPASSWD: ALL"

perm1_exist=0
perm2_exist=0

# Require sudo 
if [[ $UID != 0 ]]; then
    echo "Please run this script with sudo:"
    echo "sudo $0 $*"
    exit 1
fi

# Check if any permission is given
while IFS= read -r line
do
  if grep -q "$permission1" <<< "$line"; then
    perm1_exist=1
  fi
  if grep -q "$permission2" <<< "$line"; then
    perm2_exist=1
  fi
done < "$visudo"

# Append permissons to /etc/sudoers
if [ $perm1_exist -eq 0 ]; then
  sudo echo -e $permission1 >> /etc/sudoers
fi

if [ $perm2_exist -eq 0 ]; then
  sudo echo -e $permission2 >> /etc/sudoers
fi

read -p "User is given sudo privilege. Password will not be needed. Press any key to continue" x
