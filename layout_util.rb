module Templates
  IRIS = <<~TMPL
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },                           {0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },                           {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },                           {2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{tc,0,0},         {tc,0,1},{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      {4, 3  },{4, 4  },{4, 5  },                  {4, 6  },{4, 7  },{4, 8  }
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  TMPL

  CORNE = <<~TMPL
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

  GERGO = <<~TMPL
    //┌──────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬──────────┐
         {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },                           {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },  {1, 11 },
    //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
         {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },{tc,0,0},         {tc,0,1},{2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },  {2, 11 },
    //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼──────────┤
         {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{tc,1,0},         {tc,1,1},{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },  {3, 11 },
    //└──────────┴────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┴──────────┘
    //                               ┌────────┐┌────────┐                                      ┌────────┐┌────────┐
                                      {4, 3, }, {4, 4, },                                       {4, 7  }, {4, 8  },
    //                               └────────┘└────────┘       ┌────────┐    ┌────────┐       └────────┘└────────┘
                                                                 {tc,2,0},     {tc,2,1},
    //                                                 ┌────────┼────────┤    ├────────┼────────┐
    //                                                 │        │        │    │        │        │
    //                                                 │        │        │    │        │        │
                                                        {4, 5  },{tc,3,0},     {tc,3,1},{4, 6  }
    //                                                 │        │        │    │        │        │
    //                                                 │        │        │    │        │        │
    //                                                 └────────┴────────┘    └────────┴────────┘
  TMPL

  PREONIC = <<~TMPL
    //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
       {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },{0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },{1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },{2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },{3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       {4, 0  },{4, 1  },{4, 2  },{4, 3  },{4, 4  },{4, 5  },{4, 6  },{4, 7  },{4, 8  },{4, 9  },{4, 10 },{4, 11 },
    //└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴─────────┴───────┴────────┴────────┘
  TMPL

  NYQUIST = <<~TMPL
    //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
       {0, 0  },{0, 1  },{0, 2  },{0, 3  },{0, 4  },{0, 5  },         {0, 6  },{0, 7  },{0, 8  },{0, 9  },{0, 10 },{0, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
       {1, 0  },{1, 1  },{1, 2  },{1, 3  },{1, 4  },{1, 5  },         {1, 6  },{1, 7  },{1, 8  },{1, 9  },{1, 10 },{1, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
       {2, 0  },{2, 1  },{2, 2  },{2, 3  },{2, 4  },{2, 5  },         {2, 6  },{2, 7  },{2, 8  },{2, 9  },{2, 10 },{2, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
       {3, 0  },{3, 1  },{3, 2  },{3, 3  },{3, 4  },{3, 5  },         {3, 6  },{3, 7  },{3, 8  },{3, 9  },{3, 10 },{3, 11 },
    //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
       {4, 0  },{4, 1  },{4, 2  },{4, 3  },{4, 4  },{4, 5  },         {4, 6  },{4, 7  },{4, 8  },{4, 9  },{4, 10 },{4, 11 },
    //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
  TMPL
end

class TemplateRenderer
  attr_reader :template_string

  def initialize(template_string, layout: , tc: [])
    @template_string = template_string
    @tc = tc
    @default = layout
  end

  attr_reader :tc, :default

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
    ?- => :KC_MINS,
    "CESC" => "CESC", # FIXME: provide definition for CSEC = CTL_T(KC_ESC)
    ?; => :KC_SCLN,
    "NQUO" => "NQUO", # FIXME: define as LT(_NAV, KC_QUOT)",
    "LSFT" => :KC_LSFT,
    ?, => :KC_COMM,
    ?. => :KC_DOT,
    ?/ => :KC_SLSH,
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


  class << self
    def base(**args)
      self.new.to_a(:base, **args)
    end

    def lower(**args)
      self.new.to_a(:lower, **args)
    end

    def raise(**args)
      self.new.to_a(:raise, **args)
    end
  end

  def initialize
    @config = base_config
  end

  attr_reader :config

  def to_a(layer = :base, overrides: {})
    config.fetch(layer).tap do |result|
      overrides.each do |(row, col), kc|
        result[row][col] = Key.new(kc, 0)
      end
    end
  end

  def to_s(layer = :base)
    res = ["// #@key #{layer}"]
    config.fetch(layer).each do |row|
      res << render(row)
    end

    # FIXME: strip trailing comma from last row
    res.join("\n")
  end

  private

  def render(row)
    row.map(&:to_s).join
  end

  def keycode(kc)
    KEYCODES.fetch(kc)
  end

  def base_config
    {
      base: adjust(QWERTY),
      lower: adjust(LOWER),
      raise: adjust(RAISE)
    }
  end

  Key = Struct.new(:code, :leader_space) do
    def to_s
      KEYCODES.fetch(code).to_s
    end
  end

  def adjust(keymap, spacers: {})
    rows = []

    keymap.each do |row|
      rows << row.map do |code|
        Key.new(code, 0)
      end
    end

    rows
  end

  QWERTY = [ %w[`    1    2    3    4    5    6    7    8    9    0    BSPC],
             %w[TAB  Q    W    E    R    T    Y    U    I    O    P    -],
             %w[CESC A    S    D    F    G    H    J    K    L    ;    NQUO],
             %w[LSFT Z    X    C    V    B    N    M    ,    .    /    ENT],
             %w[_    CTRL ALT  META RS   UNDS SPC  LW   LEFT DOWN UP   RIGHT],
  ]

  LOWER = [ %w[~  !  @  #  $  %    ^  &  *  (  )  _],
            %w[~  !  @  #  $  %    ^  &  *  (  )  +],
            %w[_ \[ \]  {  }  |    |  (  )  _  :  "],
            %w[_  _  _  _  _ TMUX \n  =  +  -  ?  _],
            %w[_  _  _  _  _  _    _  _  _  _  _  _],
  ]

  RAISE = [ %w[`  1  2  3  4  5  6  7  8  9  0  BSPC],
            %w[`  1  2  3  4  5  6  7  8  9  0  _],
            %w[_  _  _  VU _  _  _  -  =  _  :  \\ ],
            %w[_  _  _  VD _  _  _  _  _  -> => _],
            %w[_ _ _ _ _   BSPC DEL _  _  _  _  _],
  ]

end

# puts Keymap.new(:preonic).to_s(:base)
# puts Keymap.new(:preonic).to_s(:lower)
# puts Keymap.new(:preonic).to_s(:raise)

# puts Keymap.new(:iris).to_s(:base)
layout = Keymap.new.to_a(:lower)

CONFIGS = {
  preonic: {
    template: Templates::PREONIC,
    layers: {
      base: Keymap.base,
      lower: Keymap.lower,
      raise: Keymap.raise,
    }
  },

  iris: {
    template: Templates::IRIS,
    layers: {
      base: Keymap.base,
      lower: Keymap.lower,
      raise: Keymap.raise,
    },
    # See Template for which thumb keys belong to the cluster.
    # Generally, if the key has a cognate with the standard
    # ortholinear layout, it uses the base config.
    # In the Iris, only the upper keys (adjacent to B and N)
    # are part of the cluster; the rest are standard row 4 keys.
    thumb_cluster: {
      base: [["KC_LALT", "KC_LCTL"]]
    }
  },

  nyquist: {
    template: Templates::NYQUIST,
    layers: {
      base: Keymap.base,
      lower: Keymap.lower,
      raise: Keymap.raise,
    },
  },

  gergo: {
    template: Templates::GERGO,
    layers: {
      base: Keymap.base(
        overrides: {[1, 11] => 'BSPC'}
      ),
      lower: Keymap.lower,
      raise: Keymap.raise,
    },
    thumb_cluster: {
      base: {
      }
    }
  },

  corne: {
    template: Templates::CORNE,
    layers: {
      base: Keymap.base(
        overrides: {[1, 11] => 'BSPC'}
      ),
      lower: Keymap.lower,
      raise: Keymap.raise,
    },
    thumb_cluster: {
      base: {
      }
    }
  }
}

name, * = ARGV
_, *selected_layers = ARGV

configs = name ? CONFIGS.slice(name.to_sym) : CONFIGS
configs.each do |name, config|
  puts "\n"

  layers = config[:layers]
  if selected_layers.any?
    layers = layers.slice(*selected_layers.map(&:to_sym))
  end

  layers.each do |key, layer|
    puts "// #{name}:#{key}"
    puts TemplateRenderer.new(
      config[:template],
      layout: layer,
      tc: config.fetch(:thumb_cluster, {}).fetch(key, {})
    ).render
  end
end

# puts TemplateRenderer.new(Templates::IRIS, layout: layout, tc: [["KC_LALT", "KC_LCTL"]]).render
# TODO: layer-specific overrides for e.g. corne backspace key
# TODO: allow TC configs to use shorthand notation
# puts TemplateRenderer.new(Templates::CORNE, layout: layout).render
# puts TemplateRenderer.new(Templates::GERGO, layout: layout, tc: [
  # %w[],
  # %w[],
  # %w[KC_LALT KC_LCTL],
  # %w[KC_LSFT KC_BSPC]
# ]).render
# puts TemplateRenderer.new(Templates::NYQUIST, layout: layout).render
# puts TemplateRenderer.new(Templates::PREONIC, layout: layout).render

