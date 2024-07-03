add_rules("mode.debug", "mode.release")

-- option("pi_startup_type")
--     set_default(0)
--     set_showmenu(true)
--     set_description("Set the PikaScript startup type")

-- option("pi_startup_type")
-- -- 用设定的选项值配置宏
-- if has_config("pi_startup_type") then
--     add_defines("PIKA_STARTUP_TYPE_INT=" .. get_config("pi_startup_type"))
-- end


target("pikapython")
    set_kind("binary")
    add_includedirs("pikapython/pikascript-api","pikapython/pikascript-core","pikapython/pikascript-lib/PikaStdLib")

    add_files("src/*.c")
   -- add_defines("DEBUG")
    add_files("pikapython/**.c")
    add_defines("PIKA_STARTUP_TYPE_INT=START_FROM_LIB")

     after_build(function (target)
        -- 获取当前构建的文件路径
        local src_file = target:targetfile()
        -- 指定目标目录
        local dest_dir = "pikapython"
        -- 确保目标目录存在
        os.mkdir(dest_dir)
        -- 移动文件
        os.mv(src_file, path.join(dest_dir, path.filename(src_file)))
        print("Moved " .. src_file .. " to " .. dest_dir)
    end)
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--
