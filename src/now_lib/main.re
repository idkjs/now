/**************************************************************************/
/*                                                                        */
/*  Copyright (c) 2021 Alain Armand <aarmand.inbox@gmail.com>             */
/*                                                                        */
/*  All rights reserved.                                                  */
/*  This file is distributed under the terms of the GNU Lesser General    */
/*  Public License version 2.1, with the special exception on linking     */
/*  described in the LICENSE.md file in the root directory.               */
/*                                                                        */
/*                                                                        */

/**************************************************************************/
/* If you delete or rename this file, you should add
   'src/now_lib/main.ml' to the 'skip' field in "drom.toml" */
let add_units =
    (datetime: CalendarLib.Calendar.t, n: int, units: CalendarLib.Calendar.field)
    : CalendarLib.Calendar.t => {
  let period_constructor =
    switch units {
    | `Year => CalendarLib.Calendar.Period.year
    | `Month => CalendarLib.Calendar.Period.month
    | `Week => CalendarLib.Calendar.Period.week
    | `Day => CalendarLib.Calendar.Period.day
    | `Hour => CalendarLib.Calendar.Period.hour
    | `Minute => CalendarLib.Calendar.Period.minute
    | `Second => CalendarLib.Calendar.Period.second
    };
  let period = period_constructor(n);
  CalendarLib.Calendar.add(datetime, period);
};

let parse_units =
  fun
  | "years"
  | "year" => `Year
  | "months"
  | "month" => `Month
  | "days"
  | "day" => `Day
  | "hours"
  | "hour" => `Hour
  | "minutes"
  | "minute" => `Minute
  | "seconds"
  | "second" => `Second
  | anything_else => failwith(Printf.sprintf("Unrecognized unit: \"%s\"", anything_else));

let get_target_datetime =
  fun
  | `Plus(n, units) => add_units(CalendarLib.Calendar.now(), n, units)
  | `Minus(n, units) => add_units(CalendarLib.Calendar.now(), n * (-1), units);

let main = () => {
  CalendarLib.Time_Zone.change(CalendarLib.Time_Zone.Local);
  switch (Array.length(Sys.argv)) {
  | 4 =>
    let n = int_of_string(Sys.argv[2]);
    let units = parse_units(Sys.argv[3]);
    let time_shift =
      switch Sys.argv[1] {
      | "plus" => `Plus((n, units))
      | "minus" => `Minus((n, units))
      | _ => failwith("Only plus or minus are supported")
      };
    get_target_datetime(time_shift)
    |> CalendarLib.Printer.Calendar.sprint("%Y-%m-%dT%H:%M:%S")
    |> print_endline;
  | 1 =>
    CalendarLib.Calendar.now()
    |> CalendarLib.Printer.Calendar.sprint("%Y-%m-%dT%H:%M:%S")
    |> print_endline
  | _ => print_endline("USAGE: now (plus|minus) n (years|months|days|hours|minutes|seconds)")
  };
};
