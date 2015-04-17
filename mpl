#!/usr/bin/env lua
-- mpl.lua
-- pops up a zenity file-selection to ask
-- for files to play with mplayer

local command = 'mplayer'

function split(str, sep)
  local st = 1
  local tbl = {}
  while st < #str do
    local fin = str:find(sep, st)
    if fin then
      table.insert(tbl, str:sub(st, fin-1))
      st = fin + 1
    else
      table.insert(tbl, str:sub(st))
      return tbl
    end
  end
end

function exec(cmd)
  local file = io.popen(cmd)
  return file:read('a'):sub(1, -2) -- strip '\n'
end

-- TODO: file selection should not pop up again afer user quits mplayer
-- TODO: escape special chars
while 1 do
  local files = exec('zenity --file-selection --multiple --filename="$HOME/"')
  if files == "" then
    break
  end
  local str = split(files, '|')
  os.execute(command .. ' "' .. table.concat(str, '" "')..'"')
end
