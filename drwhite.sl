variable fg = "black"; variable bg = "white";
set_color("normal", fg, bg);	       % default fg/bg
set_color("status", "black", "brightblue");  % status or mode line
set_color("region", "black", "blue");  % for marking regions
set_color("operator", fg, bg);	       % +, -, etc..
set_color("number", fg, bg);           % 10, 2.71,... TeX formulas
set_color("comment", "brown", bg);    % /* comment */
set_color("string", "green", bg);      % "string" or 'char'
set_color("keyword", fg, bg);          % if, while, unsigned, ...
set_color("keyword1", fg, bg);         % malloc, exit, etc...
set_color("delimiter", fg, bg);        % {}[](),.;...
set_color("preprocess", "green", bg);  % #ifdef ....
set_color("message", "brightblue", bg);% color for messages
set_color("error", "yellow", bg);         % color for errors
set_color("dollar", "red", bg);        % color dollar sign continuat$
set_color("...", "red", bg);	       % folding indicator

set_color("menu_char", "black", "blue");
set_color("menu", "lightgray", "blue");
set_color("menu_popup", "lightgray", "blue");
set_color("menu_shadow", "blue", "black");
set_color("menu_selection", "green", "red");
set_color("menu_selection_char", "yellow", "red");

set_color("cursor", "black", "red");
set_color("cursorovr", "black", "red");

set_color("trailing_whitespae", "yellow", bg);
