class ConfigRenderer
  KEYCODES = {
    ?` => :KC_GRV,
    ?1 => :KC_1,
    ?2 => :KC_2,
    ?3 => :KC_3,
    ?4 => :KC_4,
    ?5 => :KC_5,
    ?6 => :KC_6,
    ?7 => :KC_7,
    ?8 => :KC_8,
    ?9 => :KC_9,
    ?0 => :KC_0,
    "BSPC" => :KC_BSPC,
    "TAB" => :KC_TAB,
    ?Q => :KC_Q,
    ?W => :KC_W,
    ?E => :KC_E,
    ?R => :KC_R,
    ?T => :KC_T,
    ?Y => :KC_Y,
    ?U => :KC_U,
    ?I => :KC_I,
    ?O => :KC_O,
    ?P => :KC_P,
    ?A => :KC_A,
    ?S => :KC_S,
    ?D => :KC_D,
    ?F => :KC_F,
    ?G => :KC_G,
    ?H => :KC_H,
    ?J => :KC_J,
    ?K => :KC_K,
    ?L => :KC_L,
    ?Z => :KC_Z,
    ?X => :KC_X,
    ?C => :KC_C,
    ?V => :KC_V,
    ?B => :KC_B,
    ?N => :KC_N,
    ?M => :KC_M,
    "ALT" => :KC_LALT,
    "CTRL" => :KC_LCTRL,
    "-" => :KC_MINS,
    "CESC" => "CTL_T(KC_ESC)",
    ";" => :KC_SCLN,
    "NQUO" => "LT(_NAV, KC_QUOT)",
    "LSFT" => :KC_LSFT,
    "," => :KC_COMM,
    "." => :KC_DOT,
    '/' => :KC_SLSH,
    "ENT" => :KC_ENT,
    "META" => :KC_LGUI,
    "LW" => :LOWER,
    "UNDS" => :KC_UNDS,
    "SPC" => :KC_SPC,
    "RS" => :RAISE,
    "MSE" => "LT(_MOUSE, KC_BSPC)",
    "LEFT" => "KC_LEFT",
    "DOWN" => "KC_DOWN",
    "UP" => "KC_UP",
    "RIGHT" => "KC_RIGHT",
    "_" => "_______",
    ?~ => "KC_TILD",
    ?! => "KC_EXLM",
    ?@ => "KC_AT",
    ?# => "KC_HASH",
    ?$ => "KC_DLR",
    ?% => "KC_PERC",
    ?^ => "KC_CIRC",
    ?& => "KC_AMPR",
    ?* => "KC_ASTR",
    ?( => "KC_LPRN",
    ?) => "KC_RPRN",
    ?+ => "KC_PLUS",
    ?[ => "KC_LBRC",
    ?] => "KC_RBRC",
    ?{ => "KC_LCBR",
    ?} => "KC_RCBR",
    ?| => "KC_PIPE",
    ?: => "KC_COLN",
    ?" => "KC_DQUO",
    "TMUX" => "C(KC_B)",
    '\n' => "NEWLN",
    ?= => "KC_EQL",
    ?? => "KC_QUES",
    "VU" => "KC_VOLU",
    "VD" => "KC_VOLD",
    "\\" => "KC_BSLS",
    '->' => "LAMBDA",
    '=>' => "HSHRKT",
    "DEL" => :KC_DEL
  }

  def initialize(key)
    @key = key
    @config = send(key)
  end

  attr_reader :config

  def to_s(layer = :base)
    res = ["// #@key #{layer}"]
    config.fetch(layer).each do |index, row|
      res << render(row)
    end

    res.join("\n")
  end

  private

  def render(row)
    row.map do |kc|
      keycode(kc).to_s.rjust(8)
    end.join(",")
  end

  def keycode(kc)
    KEYCODES.fetch(kc)
  end

  def preonic
    {
      base: QWERTY,
      lower: LOWER,
      raise: RAISE
    }
  end

  QWERTY = {
    0 => %w[`    1    2    3    4    5    6    7    8    9    0    BSPC],
    1 => %w[TAB  Q    W    E    R    T    Y    U    I    O    P    -],
    2 => %w[CESC A    S    D    F    G    H    J    K    L    ;    NQUO],
    3 => %w[LSFT Z    X    C    V    B    N    M    ,    .    /    ENT],
    4 => %w[_    CTRL ALT  META RS   UNDS SPC  LW   LEFT DOWN UP   RIGHT],
  }

  LOWER = {
    0 => %w[~ ! @ # $ % ^ & * ( ) _],
    1 => %w[~ ! @ # $ % ^ & * ( ) +],
    2 => %w[_ \[ \] { } | | ( ) _ : "],
    3 => %w[_ _ _ _ TMUX \n = + - ? _],
    4 => %w[_ _ _ _ _ _ _ _ _ _ _ _],
  }

  RAISE = {
    0 => %w[`  1  2  3  4  5  6  7  8  9  0  BSPC],
    1 => %w[`  1  2  3  4  5  6  7  8  9  0  _],
    2 => %w[_  _  _  VU _  _  _  -  =  _  :  \\ ],
    3 => %w[_  _  _  VD _  _  _  _  _  -> => _],
    4 => %w[_ _ _ _ _   BSPC DEL _  _  _  _  _],
  }

end

puts ConfigRenderer.new(:preonic).to_s(:base)
puts ConfigRenderer.new(:preonic).to_s(:lower)
puts ConfigRenderer.new(:preonic).to_s(:raise)
