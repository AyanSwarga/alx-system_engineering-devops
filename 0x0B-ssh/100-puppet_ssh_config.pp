# This Puppet script set up ssh config file

file_line { 'Turn off passwd auth':
  ensure => 'present',
  path   => '/etc/ssh/ssh_config',
  line   => 'PasswordAuthentication no',
}

file_line { 'Identity file':
  ensure => 'present',
  path   => '/etc/ssh/ssh_config',
  line   => 'IdentityFile ~/.ssh/school',
}
