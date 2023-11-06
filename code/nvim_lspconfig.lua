---@class lsp_servers
return {
  clangd = {
    binary = "clangd",
    cmd = {
      'clangd',
      -- '/home/max/Downloads/esp-clang/bin/clangd',
      -- '--query-driver=/home/max/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-*',
      -- '--query-driver=C:/Program Files (x86)/IAR Systems/Embedded Workbench 8.4 arm 8.50.9/arm/bin/iccarm.exe',
      '--background-index',
      '--clang-tidy',
      '--enable-config',
    },
    root_dir = {
      "compile_commands.json",
      ".git"
    },
  }
}
