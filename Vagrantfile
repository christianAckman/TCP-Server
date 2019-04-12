Vagrant.configure("2") do |config|

  config.vm.provider "virtualbox" do |v|
    v.name = "debian-stretch"
    v.memory = 2048
    v.cpus = 4
  end

    # Choose distro
    config.vm.box = "debian/stretch64"

    # Mount directory from host
    config.vm.synced_folder "./", "/code"

    # Run provisioners
    config.vm.provision :shell, path: "provision.sh"

    # Create eth1 interface
    config.vm.network :private_network, bridge: "en0: Wi-Fi (Wireless)", ip: "192.168.33.50"

end
