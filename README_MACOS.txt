To get gdb to work on MacOS 10.14

1. install gdb 9
brew install gdb
brew link --overwrite gdb               # not sure this was necessary
brew unlink gdb && brew link gdb        # not sure this was necessary

2. echo "set startup-with-shell off" >> ~/.gdbinit

3. set up certificate with the KeyChain Access tool
4. restart taskgated:
        sudo killall taskgated

5. check gdb is codesigned:
        code sign -dv --verbose=4 $(which gdb)

6. then create an entitlements file (say ~/gdb.xml)
==========================================================
        <?xml version="1.0" encoding="UTF-8"?>
        <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
        <plist version="1.0">
            <dict>
                <key>com.apple.security.cs.debugger</key>
                <true/>
            </dict>
        </plist>
==========================================================

7. codesign --entitlements ~/gdb.xml -fs gdb-cert $(which gdb)

Then gdb worked on the command line.  Homebrew installed gdb as a symlink in:
        /usr/local/bin/gdb

