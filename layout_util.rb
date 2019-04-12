#! /usr/bin/env ruby

module Templates
  IRIS = <<-TMPL
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },                           {0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },                           {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },                           {2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{tc,0,0},         {tc,0,1},{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  {tc,1,0},{tc,1,1},{tc,1,2},                  {tc,1,3},{tc,1,4},{tc,1,5}
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
TMPL

  # NOTE: The thumb keys here are just mapped to the middle of R4, but could also
  # be configured as a thumb cluster (see Iris template and config)
  CORNE = <<-TMPL
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },                           {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },                           {2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ┌────────┼────────┼────────┼────────┼────────┼────────┤
   {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },                           {3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  {4, 3  },{4, 4  },{4, 5  },                  {4, 6  },{4, 7  },{4, 8  }
//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
TMPL

  GERGO = <<-TMPL
//┌──────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬──────────┐
     {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },                           {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },  {1, 11 },
//├──────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
     {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },{tc,0,0},         {tc,0,1},{2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },  {2, 11 },
//├──────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
     {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{tc,1,0},         {tc,1,1},{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },  {3, 11 },
//└──────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴──────────┘
//                               ┌────────┐┌────────┐                                      ┌────────┐┌────────┐
                                  {tc,2,0}, {tc,2,1},                                       {tc,2,2}, {tc,2,3},
//                               └────────┘└────────┘       ┌────────┐    ┌────────┐       └────────┘└────────┘
                                                             {tc,3,0},     {tc,3,1},
//                                                 ┌────────┼────────┤    ├────────┼────────┐
//                                                 │        │        │    │        │        │
//                                                 │        │        │    │        │        │
                                                    {tc,4,0},{tc,4,1},     {tc,4,2},{tc,4,3}
//                                                 │        │        │    │        │        │
//                                                 │        │        │    │        │        │
//                                                 └────────┴────────┘    └────────┴────────┘
TMPL

  PREONIC = <<-TMPL
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
   {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },{0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },{1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },{2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   {4, 0  },{4, 1  },{4, 2  },{4, 3  },{4, 4  },{4, 5  },{4, 6  },{4, 7  },{4, 8  },{4, 9  },{4, 10 },{4, 11 }
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
TMPL

  NYQUIST = <<-TMPL
//┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
   {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },         {0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },         {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },         {2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },         {3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
//├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
   {4, 0  },{4, 1  },{4, 2  },{4, 3  },{4, 4  },{4, 5  },         {4, 6  },{4, 7  },{4, 8  },{4, 9  },{4, 10 },{4, 11 }
//└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘

TMPL
end

class TemplateRenderer
  attr_reader :template_string

  def initialize(template_string, layout:, output_headers: false)
    @template_string = template_string
    @layout = layout
    @output_headers = output_headers
  end

  def render
    result = String.new
    @mode = :print

    template_string.each_char do |char|
      if @mode == :print
        if char == '{'
          @mode = :interpolate
          @buffer = String.new
        else
          result << char
        end
      elsif @mode == :interpolate
        if char == '}'
          result << process_buffer(@buffer)
          @mode = :print
        else
          @buffer << char
        end
      end
    end

    result
  end

  def tc
    @layout[:thumb_cluster] || {}
  end

  def default
    @layout[:defaults] || {}
  end

  def process_buffer(buffer)
    args = eval("[#{buffer}]", binding)
    collection, row, col = case args.length
    when 3
      args
    when 2
      [default, *args]
    end

    (collection.dig(row, col) || Keymap::BLANK).to_s.ljust(8)
  end
end

class Keymap
  BLANK = '_______'
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
    ?- => :KC_MINS,
    ?; => :KC_SCLN,
    ?, => :KC_COMM,
    ?. => :KC_DOT,
    ?/ => :KC_SLSH,
    "BSPC" => :KC_BSPC,
    "TAB" => :KC_TAB,
    "ALT" => :KC_LALT,
    "CTRL" => :KC_LCTRL,
    "LSFT" => :KC_LSFT,
    "ENT" => :KC_ENT,
    "META" => :KC_LGUI,
    "LW" => :LOWER,
    "UNDS" => :KC_UNDS,
    "SPC" => :KC_SPC,
    "RS" => :RAISE,
    "LEFT" => "KC_LEFT",
    "DOWN" => "KC_DOWN",
    "UP" => "KC_UP",
    "RIGHT" => "KC_RIGHT",
    "HOME" => :KC_HOME,
    "PGDN" => :KC_PGDN,
    "PGUP" => :KC_PGUP,
    "END" => :KC_END,
    ?_ => BLANK,
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
    '\n' => :NEWLN,
    ?= => :KC_EQL,
    ?? => :KC_QUES,
    "VU" => :KC__VOLUP,
    "VD" => :KC__VOLDOWN,
    "\\" => :KC_BSLS,
    "DEL" => :KC_DEL,
    "MUT" => :KC__MUTE,
    "MSD" => "KC_MS_D",
    "MSR" => "KC_MS_R",
    "MSL" => "KC_MS_L",
    "MSU" => "KC_MS_U",
    "B1"  => "KC_BTN1",
    "B2"  => "KC_BTN2",
    "B3"  => "KC_BTN3",
    "F1"  => "KC_F1",
    "F2"  => "KC_F2",
    "F3"  => "KC_F3",
    "F4"  => "KC_F4",
    "F5"  => "KC_F5",
    "F6"  => "KC_F6",
    "F7"  => "KC_F7",
    "F8"  => "KC_F8",
    "F9"  => "KC_F9",
    "F10"  => "KC_F10",
    "F11"  => "KC_F11",
    "F12"  => "KC_F12",
    "RESET" => :RESET,

    # keycodes for send_string
    '->' => :LAMBDA,
    '=>' => :HSHRKT,

  }

  # FIXME: export these as defines
  CUSTOM = {
    "CESC" => "CTL_T(KC_ESC)",
    "NQUO" => "LT(_NAV, KC_QUOT)",
    "MSPC" => "LT(_MOUSE, KC_BSPC)",
    "ASPC" => "ALT_T(KC_BSPC)",
    "TMUX" => "C(KC_B)",
    "ZI" => [:TZM_IN, "LCTL(LSFT(KC_EQL))"],
    "ZO" => [:TZM_OUT, "LCTL(LSFT(KC_MINS))"],

    # Spectacle (mac only)
    "SW" => [:SPECW, "KC_F9"],
    "SL" => [:SPECL, "LCTL(LGUI(KC_LEFT))"],
    "SF" => [:SPECF, "LCTL(LGUI(KC_UP))"],
    "SR" => [:SPECR, "LCTL(LGUI(KC_RIGHT))"],
  }

  CustomKeycode = Struct.new(:name, :definition) do
    def to_s
      name.to_s
    end

    def define
      "#define #{name} #{definition}"
    end
  end

  def self.try_fetch_custom(code)
    name, definition = CUSTOM.fetch(code)
    if !definition
      definition = name
      name = code
    end

    CustomKeycode.new(name, definition)
  end

  def initialize
    @config = base_config
  end

  attr_reader :config

  def to_h(layer = :base, overrides: {}, thumb_cluster: {}, thumb_cluster_mapping: {})
    # overrides can be given as an array of hashes or a single hash.
    if overrides.is_a?(Array)
      overrides = overrides.inject(:merge)
    end

    defaults = config.fetch(layer).tap do |result|
      overrides.each do |(row, col), kc|
        result[row][col] = Key.new(kc, 0)
      end
    end

    mapped_thumb_cluster = {}

    thumb_cluster_mapping.each do |(row, col), (crow, ccol)|
      mapped_thumb_cluster[crow] ||= {}
      mapped_thumb_cluster[crow][ccol] = defaults.dig(row, col)
    end

    thumb_cluster.each do |(row, col), kc|
      mapped_thumb_cluster[row] ||= {}
      mapped_thumb_cluster[row][col] = Key.new(kc, 0)
    end

    { defaults: defaults, thumb_cluster: mapped_thumb_cluster }
  end

  private

  def base_config
    {
      base:  adjust(QWERTY),
      lower: adjust(LOWER),
      raise: adjust(RAISE),
      nav:   adjust(NAV),
      mouse: adjust(MOUSE),
      adjust: adjust(ADJUST),
    }
  end

  Key = Struct.new(:code, :leader_space) do
    def to_s
      KEYCODES.fetch(code) { try_fetch_custom }.to_s
    end

    def define
      nil
    end

    private

    def try_fetch_custom
      Keymap.try_fetch_custom(code)
    end
  end

  def adjust(keymap, spacers: {})
    rows = []

    keymap.each do |row|
      rows << row.map do |code|
        Key.new(code)
      end
    end

    rows
  end

  QWERTY = [ %w[`    1    2    3    4    5    6    7    8    9    0    BSPC],
             %w[TAB  Q    W    E    R    T    Y    U    I    O    P    -],
             %w[CESC A    S    D    F    G    H    J    K    L    ;    NQUO],
             %w[LSFT Z    X    C    V    B    N    M    ,    .    /    ENT],
             %w[_    CTRL ALT  META LW   UNDS SPC  RS   LEFT DOWN UP   RIGHT],
  ].each(&:freeze).freeze

  # FIXME: the BSPC overriding escape/ctrl here can be unwieldy, and
  # I've probably never used it
  LOWER = [ %w[~     !  @  #  $  %    ^  &  *  (  )  _],
            %w[~     !  @  #  $  %    ^  &  *  (  )  +],
            %w[BSPC \[ \]  {  }  |    |  (  )  _  :  "],
            %w[_     ZO ZI ~  ` TMUX \n  =  +  -  ?  _],
            %w[_     _  _  _  _  _    _  _  _  _  _  _],
  ].each(&:freeze).freeze

  RAISE = [ %w[`   1  2  3  4  5  6  7  8  9  0  BSPC],
            %w[`   1  2  3  4  5  6  7  8  9  0  _],
            %w[_   _  _  VU _  .  .  -  =  _  :  \\ ],
            %w[MUT _  _  VD _  _  _  _  _  -> => _],
            %w[_   _ _ _ _   BSPC DEL _  _  _  _  _],
  ].each(&:freeze).freeze

  NAV =   [ %w[_   _   _   _   _   _   _   _   _   _   _   _],
            %w[_   _   SW  _   _   _   _   _   _   _   _   _],
            %w[_   SL  SF  SR  _   _ LEFT DOWN UP RIGHT _  _],
            %w[_   ZI  ZO  _   _   _   _   _   _   _   _   _],
            %w[_   _   _   _   _   _   _   _   _   _   _   _],
  ].each(&:freeze).freeze

  MOUSE = [ %w[_   _   _   _   _   _   _   _   _   _   _   _],
            %w[_   _   _   _   _   _   _   _  MSU  _   _   _],
            %w[_   _   _   _   _   _   _  MSL MSD MSR  _   _],
            # FIXME: this button layout doesn't make sense on a non-split keyboard
            %w[_   _   _   _   _   B3  B3  _   _   _   _   _],
            %w[_   _   _   _   _   B1  B1  _   _   _   _   _],
  ].each(&:freeze).freeze

  ADJUST = [%w[_   F1  F2  F3  F4  F5  F6  F7  F8  F9  F10 F11],
            %w[_ RESET _   _   _   _   _   _   _   _   _   F12],
            %w[_   _   _   _   _   _   _   _   _   _   _   _],
            %w[_   _   _   _   _   _   _   _   _   _   _   _],
            %w[_   _   _   _   _   _   _   _   _   _   _   _],
  ].each(&:freeze).freeze
end

ROW_1_BACKSPACE = { [1, 11] => "BSPC" }
PREONIC_ARROW_NAV = {
  [4, 8] => "HOME",
  [4, 9] => "PGUP",
  [4, 10] => "PGDN",
  [4, 11] => "END",
}

CONFIGS = {
  preonic: {
    layout_macro: "LAYOUT_preonic_grid",
    template: Templates::PREONIC,
    layers: {
      base: {},
      lower: {},
      raise: {},
      nav: {
        overrides: PREONIC_ARROW_NAV
      },
    }
  },

  iris: {
    path: "keebio/iris",
    template: Templates::IRIS,
    # In the first pass, the Keymap will map from the row-based layout to
    # the thumb_cluster layout.
    thumb_cluster_mapping: {
      [4,3] => [1,0],
      [4,4] => [1,1],
      [4,5] => [1,2],
      [4,6] => [1,3],
      [4,7] => [1,4],
      [4,8] => [1,5],
    },
    layers: {
      base: {
        # This MSPC could also go in the thumb_cluster config.
        # `overrides` are applied to the base row layout.
        overrides: {[4, 8] => "MSPC"},
        thumb_cluster: { [0, 0] => "ALT", [0, 1] => "CTRL", }
      },
      lower: {},
      raise: {},
      nav: {
        thumb_cluster: {
          [0, 0] => "HOME", [0, 1] => "PGUP",
          [1, 2] => "END",  [1, 3] => "PGDN",
        }
      },
      adjust: {
        thumb_cluster: {
          [0, 1] => "VU",
          [1, 3] => "VD",
        }

      },
      mouse: { thumb_cluster: { [0, 0] => "B2", [0, 1] => "B2" }},
    },
    # See Template for which thumb keys belong to the cluster.
    # Generally, if the key has a cognate with the standard
    # ortholinear layout, it uses the base config.
    # In the Iris, only the upper keys (adjacent to B and N)
    # are part of the cluster; the rest are standard row 4 keys.
    #
  },

  nyquist: {
    path: "keebio/nyquist",
    template: Templates::NYQUIST,
    layers: {
      base: {},
      lower: {},
      raise: {},
      nav: {
        overrides: PREONIC_ARROW_NAV
      },
    },
  },

  gergo: {
    template: Templates::GERGO,
    layout_macro: "LAYOUT_GERGO",
    thumb_cluster_mapping: {
      [4, 3] => [2, 0],
      [4, 4] => [2, 1],
      [4, 5] => [4, 0],
      [4, 6] => [4, 3],
      [4, 7] => [2, 2],
      [4, 8] => [2, 3],
    },
    layers: {
      base: { overrides: ROW_1_BACKSPACE },
      lower: {},
      raise: {},
      nav: {},
    },
  },

  corne: {
    template: Templates::CORNE,
    layers: {
      # TODO: mouse keys
      base: {
        overrides: [
          ROW_1_BACKSPACE,
          { [4, 8] => "ASPC" }
        ]
      },
      lower: {
        overrides: ROW_1_BACKSPACE
      },
      raise: {},
      adjust: {},
      nav: {
        overrides: {
          [3, 5] => "HOME",
          [4, 5] => "END",
          [3, 6] => "PGUP",
          [4, 6] => "PGDN"
        }
      },
    }
  }
}

CONFIGS[:crkbd] = CONFIGS[:corne]

def render(name:, config:, selected_layers: [], render_opts: {})
  puts "\n"

  output = render_opts[:io] || $stdout
  header_mode = render_opts[:output_headers]
  layout_macro = config.fetch(:layout_macro, "LAYOUT")

  layers = config[:layers]
  if selected_layers.any?
    layers = layers.slice(*selected_layers.map(&:to_sym))
  end

  layers.each do |key, layer|
    layout = Keymap.new.to_h(key, **layer, **config.slice(:thumb_cluster_mapping))

    output.puts (header_mode ? "#define #{name.upcase}__#{key.upcase} #{layout_macro}( \\" : "// #{name}:#{key}")
    TemplateRenderer.new(
      config[:template],
      layout: layout,
      **render_opts.slice(:output_headers)
    ).render.lines.each do |line|
      if header_mode
        next if line.strip.start_with?('//')
        output.puts "#{line.split(',').map(&:strip).join(',')} \\"
      else
        output.puts line
      end
    end

    output.puts ")" if header_mode
  end
end

def save_header_file(name:, config:, selected_layers: [], render_opts: {})
  keyboard_path = config.fetch(:path, name)
  file = File.open(File.expand_path("../keyboards/#{keyboard_path}/keymaps/zvkemp/generated.h", __FILE__), "w")

  Keymap::CUSTOM.each do |key, config; name|
    name, definition = config

    unless definition
      definition = name
      name = key
    end

    file.puts Keymap::CustomKeycode.new(name, definition).define
  end

  render(
    name: name,
    config: config,
    selected_layers: selected_layers,
    render_opts: render_opts.merge(io: file, output_headers: true)
  )

  file.close
end

name, *selected_layers = ARGV

if name == "header"
  name, *selected_layers = ARGV.drop(1)
  config = CONFIGS.fetch(name.to_sym)
  save_header_file(name: name, config: config, selected_layers: selected_layers)
  exit(0)
end

configs = name ? CONFIGS.slice(name.to_sym) : CONFIGS
configs.each do |name, config|
  render(name: name, config: config, selected_layers: selected_layers)
end
